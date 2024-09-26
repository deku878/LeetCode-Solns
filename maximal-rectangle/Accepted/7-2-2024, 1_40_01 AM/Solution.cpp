// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    vector<int> nxtg(vector<int>& x, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = x[i];
            while (st.top() != -1 && x[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> preg(vector<int>& x, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            int curr = x[i];
            while (st.top() != -1 && x[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));

        // Convert char matrix to int matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        // Build histogram heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

        int area = 0;
        for (int i = 0; i < m; i++) {
            vector<int> nxt = nxtg(mat[i], n);
            vector<int> prev = preg(mat[i], n);
            for (int j = 0; j < n; j++) {
                int height = mat[i][j];
                if (nxt[j] == -1) {
                    nxt[j] = n;
                }
                int width = nxt[j] - prev[j] - 1;
                area = max(area, height * width);
            }
        }
        return area;
    }
};
