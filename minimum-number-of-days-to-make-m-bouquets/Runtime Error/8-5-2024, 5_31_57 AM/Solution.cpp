// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool checker(vector<int>&bloomDay,int mid,int k,int m){
        int cnt=0;
        int bo=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                bo++;
            }
            else{
                cnt+=bo/k;
                bo=0;
            }
        }
        cnt+=bo/k;
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<m*k){
            return -1;
        }
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(checker(bloomDay,mid,k,m)){
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