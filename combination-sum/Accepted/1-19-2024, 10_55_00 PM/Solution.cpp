// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void findCombination(int i, int target, vector<int> &candidates, vector<vector<int>> &result, vector<int> &temp)
    {
        if(i==candidates.size())
        {
            if(target==0)
                result.push_back(temp);
        return;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            findCombination(i,target-candidates[i],candidates,result,temp);
            temp.pop_back();
        }
        findCombination(i+1,target,candidates,result,temp);       
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        findCombination(0, target, candidates, result, temp);
    return result;
    }
};