// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        long long int n=candidates.size();
        vector<vector<int>>p;
        for(int i=0;i<(1<<n);i++){
            vector<int>k;
            int sum=0;
            for(int j=0;j<n;j++){
                if(1<<j & i){
                    sum+=candidates[j];
                    k.push_back(candidates[j]);
                }
            }
            sort(k.begin(),k.end());
            if(sum==target and find(p.begin(),p.end(),k)==p.end()){
                p.push_back(k);
            }
        }
        return p;
    }
};