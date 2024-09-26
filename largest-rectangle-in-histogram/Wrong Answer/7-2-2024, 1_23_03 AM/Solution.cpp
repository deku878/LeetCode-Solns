// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    vector<int>nxtg(vector<int>&a,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=a[i];
            if(st.top()!=-1 and a[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prs(vector<int>&a,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=a[i];
            if(st.top()!=-1 and a[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nxt=nxtg(heights,heights.size());
        vector<int>prev=prs(heights,heights.size());
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int a=heights[i];
            if(nxt[i]==-1){
                nxt[i]=heights.size();
            }
            int b=nxt[i]-prev[i]-1;
            area=max(area,a*b);
        }
        return area;
    }
};