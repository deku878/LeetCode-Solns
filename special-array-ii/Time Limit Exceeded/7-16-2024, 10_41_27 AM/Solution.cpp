// https://leetcode.com/problems/special-array-ii

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            bool check=true;
        for(int j=queries[i][0]+1;j<=queries[i][1];j++){
            if(nums[j-1]%2==nums[j]%2){
                check=false;
                break;
            }
        }
        ans[i]=check;
        }
        return ans;
    }
};