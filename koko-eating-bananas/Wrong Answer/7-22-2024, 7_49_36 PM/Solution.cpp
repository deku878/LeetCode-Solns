// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool helper(int h,int mid,vector<int>&piles){
        int p=0;
        for(int i=0;i<piles.size();i++){
            p+=((piles[i]+mid-1)/(mid));
        }
        return p<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int lo=piles[0];
        int hi=piles[piles.size()-1];
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(helper(h,mid,piles)){
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