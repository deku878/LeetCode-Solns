// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool checker(vector<int>&weights,int days,int mid){
        int sum=0;
        int cnt=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid){
                return false;
            }
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                cnt++;
                sum=weights[i];
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(checker(weights,days,mid)){
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