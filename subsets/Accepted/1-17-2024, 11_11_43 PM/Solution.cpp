// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long long int n=nums.size();
        vector<vector<int>>f;
        for(int i=0;i<(1<<n);i++){
             vector<int>c;
            for(int j=0;j<n;j++){    
                if((i & 1<<j)){
                    c.push_back(nums[j]);
                }
            }
            f.push_back(c);
        }
        return f;
    }
};