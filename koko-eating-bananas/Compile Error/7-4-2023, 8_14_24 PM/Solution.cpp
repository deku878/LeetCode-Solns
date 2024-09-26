// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
long long int totalhours(vector<long long int>&nums,long long int hourly){
    long long int totalh=0;
    long long int n=nums.size();
    for(long long int i=0;i<n;i++){
        totalh+=ceil((double)nums[i] / (double)hourly);
    }
    return totalh;
}
    long long int minEatingSpeed(vector<long long int>& piles, long long int h) {
        long long int start=1;
        long long int end=*max_element(piles.begin(), piles.end());
        while(start<=end){
            long long int mid=start+(end-start)/2;
            if(totalhours(piles,mid)>h){
                start=mid+1;
            }
            else if(totalhours(piles,mid)<=h){
                end=mid-1;
            }
        }
        return start;
}
};