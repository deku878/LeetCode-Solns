// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX/2));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(auto e:edges){
            int s=e[0];
            int d=e[1];
            int w=e[2];
            dis[s][d]=w;
            dis[d][s]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j]; 
                    }
                }
            }
        }
        long long int mini=INT_MAX;
        vector<int>count(n,0);
        for(int i=0;i<n;i++){
            long long int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=dt and i!=j){
                    cnt++;
                }
            }
            mini=min(mini,cnt);
            count[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            if(count[i]==mini){
                return i;
            }
        }
        return -1;
    }
};
