// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool isvalid(vector<long long int>&piles,long long int mid,int h){
        long long int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]+mid-1)/mid;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long int lo=1;
        long long int hi=1e9;
        long long int ans=-1;
        vector<long long int>x;
        for(int i=0;i<piles.size();i++){
            x.push_back(piles[i]);
        }
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isvalid(x,mid,h)){
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