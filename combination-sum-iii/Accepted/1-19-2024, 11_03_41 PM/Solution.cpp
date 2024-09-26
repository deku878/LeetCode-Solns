// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>c;
        for(int i=0;i<(1<<a.size());i++){
            vector<int>h;
            int sum=0;
            for(int j=0;j<a.size();j++){
                if(i&(1<<j)){
                    sum+=a[j];
                    h.push_back(a[j]);
                }
                
            }
            if(sum==n and h.size()==k){
                c.push_back(h);
            }
        }
        return c;
    }
};