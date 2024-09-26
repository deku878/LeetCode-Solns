// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool isvalid(vector<long long int>&c,long long int mid,int k,int m){
        int cx=0;
        int cnt=0;
        for(int i=0;i<c.size();i++){
            if(cx==k){
                cnt++;
                cx=0;
            }
            if(c[i]<=mid){
                cx++;
            }
            else{
                cx=0;
            }
        }
        if(cx==k){
            cnt++;
        }
        return cnt>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        vector<long long int>y;
        for(int i=0;i<b.size();i++){
            y.push_back(b[i]);
        }
        long long int lo=1;
        long long int hi=1e9;
        long long int ans=-1;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isvalid(y,mid,k,m)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};