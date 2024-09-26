// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
   bool checker(vector<int>&piles,int mid,int h){
    int ch=0;
    for(int i=0;i<piles.size();i++){
        ch+=(piles[i]+mid-1)/(mid);
    }
    return ch<=h;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(checker(piles,mid,h)){
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