// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mp;
        vector<int>vis(60,0);
        for(int i=0;i<time.size();i++){
            time[i]%=60;
            
            mp[time[i]]++;
        }
        int cnt=0;
        for(auto m:mp){
            if(m.first==0 or m.first==30){
                int cnt1=0;
                cnt1+=((m.second)*(m.second-1))/2;
                cnt+=cnt1;
                cout<<cnt1<<" "<<m.first<<endl;
                vis[0]=1;
            }
            else if(!vis[60-m.first] and !vis[m.first]){
                int cnt1=0;
                cnt1+=(m.second)*(mp[60-m.first]);
                cnt+=cnt1;
                cout<<cnt1<<" "<<m.first<<endl;
                vis[60-m.first]=1;
                vis[m.first]=1;
            }
        }
        return cnt;
    }
};