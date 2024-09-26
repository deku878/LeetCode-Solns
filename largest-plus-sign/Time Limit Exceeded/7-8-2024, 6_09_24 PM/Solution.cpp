// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> t(n, vector<int>(n, 1));
        
        for(vector<int>& vec : mines) {
            t[vec[0]][vec[1]] = 0;
        }
        
        int maxC = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
				//As soon as you see one, find 1 to its left, right, top and bottom
                if(t[i][j] == 1) {
                    int k = j+1;
                    int right = 0, left = 0, up = 0, down = 0;
                    while(k < n && t[i][k] == 1) {
                        k++;
                        right++;
                    }
                    
                    k = j-1;
                    while(k >= 0 && t[i][k] == 1) {
                        k--;
                        left++;
                    }
                    
                    k = i-1;
                    while(k >= 0 && t[k][j] == 1) {
                        k--;
                        up++;
                    }
                    
                    k = i+1;
                    while(k < n && t[k][j] == 1) {
                        k++;
                        down++;
                    }
                    
                    int minL = min({left, right, up, down});
                    maxC = max(maxC, minL+1);
                }
            }
        }
        return maxC;
    }
};
