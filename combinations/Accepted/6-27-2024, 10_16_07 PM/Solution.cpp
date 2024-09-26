// https://leetcode.com/problems/combinations

class Solution {
public:
    void solve(vector<int>&r,vector<int>&res,int k,vector<vector<int>>&d,int idx){
        if(r.size()==k){
            d.push_back(r);
            return;
        }
        if(idx==res.size()){
            return;
        }
        r.push_back(res[idx]);
        solve(r,res,k,d,idx+1);
        r.pop_back();
         solve(r,res,k,d,idx+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(i+1);
        }
        vector<vector<int>>f;
        vector<int>t;
        solve(t,res,k,f,0);
        return f;
    }
};