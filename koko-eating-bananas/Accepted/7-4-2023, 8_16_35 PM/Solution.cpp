// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
long long int totalhours(vector<int>&nums,long long int hourly){
    long long int totalh=0;
    int n=nums.size();
    for(long long int i=0;i<n;i++){
        totalh+=ceil((double)nums[i] / (double)hourly);
    }
    return totalh;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(), piles.end());
        while(start<=end){
            int mid=start+(end-start)/2;
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