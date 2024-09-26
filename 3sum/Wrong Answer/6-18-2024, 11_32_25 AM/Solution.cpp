// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>x;
        set<vector<int>>x1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int lo=i+1;
            int hi=nums.size()-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]+nums[i]==0){
                    x1.insert({nums[i],nums[lo],nums[hi]});
                    lo++;hi--;
                }
                else if(nums[lo]+nums[hi]<0){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        for(auto kl:x1){
            x.push_back(kl);
        }
        return x;
    }
};