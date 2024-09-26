// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool isvalid(vector<long long int>&v,long long int mid,long long int t){
        long long int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=(v[i]+mid-1)/mid;
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        vector<long long int>x;
        for(int i=0;i<nums.size();i++){
            x.push_back(nums[i]);
        }
        long long int lo=1;
        long long int hi=1e9;
        long long int ans=-1;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isvalid(x,mid,t)){
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