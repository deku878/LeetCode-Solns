// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool checker(vector<int>&bloomDay,int m,int k,int mid){
        int x=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                x++;
                cnt=0;
            }
        }
        x+=(cnt)/k;
        return x>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(checker(bloomDay,m,k,mid)){
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