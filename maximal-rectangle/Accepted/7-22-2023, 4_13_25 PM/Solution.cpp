// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
   vector<int> nextsmaller(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (s.top()!=-1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevsmaller(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (s.top()!=-1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

        int area(vector<int>heights){
            int n=heights.size();
            vector<int>prev(n);
            prev=prevsmaller(heights,n);
            vector<int>next(n);
            next=nextsmaller(heights,n);
            int sum=INT_MIN;
            for(int i=0;i<n;i++){
                int l=heights[i];
                if(next[i]==-1){
                    next[i]=n;
                }
                 int b=next[i]-prev[i]-1;
                int newarea=l*b;
                sum=max(sum,newarea);
            }
            return sum;
        }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v(matrix.size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0'){
                    v[i].push_back(0);
                }
                else{
                    v[i].push_back(1);
                }
            }
        }
        int maxarea=area(v[0]);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(v[i][j]!=0){
                    v[i][j]=v[i][j]+v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            maxarea=max(maxarea,area(v[i]));
        }
        return maxarea;
    }
};