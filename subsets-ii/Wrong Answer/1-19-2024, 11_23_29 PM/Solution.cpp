// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>vc;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int>h;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    h.push_back(nums[j]);
                }
            }
            if(find(vc.begin(),vc.end(),h)==vc.end()){
                vc.push_back(h);
            }
        }
        return vc;
    }
};