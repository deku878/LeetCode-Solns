// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool check1(vector<int>&ok,int m,int k,int mid){
        int fool=0;
        int faltu=0;
        for(int i=0;i<ok.size();i++){
            if(ok[i]<=mid){
                faltu++;
                if(faltu==k){
                    fool++;
                    faltu=0;
                }
            }
            else{
                faltu=0;
            }
        }
        fool+=(faltu)/k;
        return fool>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo=INT_MAX;
        int hi=1e9;
        for(int i=0;i<bloomDay.size();i++){
            lo=min(bloomDay[i],lo);
        }
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check1(bloomDay,m,k,mid)){
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