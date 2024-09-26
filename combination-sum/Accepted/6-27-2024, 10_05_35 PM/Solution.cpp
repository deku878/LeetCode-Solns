// https://leetcode.com/problems/combination-sum

class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>&c,int t,vector<int>&d,int idx){
        if(t==0){
            st.insert(d);
            return;
        }
        if(idx==c.size() or t<0){
            return;
        }
        d.push_back(c[idx]);
        solve(c,t-c[idx],d,idx);
        d.pop_back();
        solve(c,t,d,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        st.clear();
        sort(c.begin(),c.end());
        vector<int>f;
        solve(c,t,f,0);
        vector<vector<int>>d(st.begin(),st.end());
        return d;
    }
};