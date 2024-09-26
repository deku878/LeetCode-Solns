// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        vector<int>v(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() and a[i%n]>=st.top()){
                st.pop();
            }
            if(!st.empty() and i<n){
                v[i]=st.top();
            }
            st.push(a[i%n]);
        }
        return v;
    }
};