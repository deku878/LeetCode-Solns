// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
           vector<vector<int>> rt;
    
    if (numRows >= 1) {
        rt.push_back(vector<int>{1}); // First row
    }
    if (numRows >= 2) {
        rt.push_back(vector<int>{1, 1}); // Second row
    }
    
    for (int i = 2; i < numRows; ++i) {
        vector<int> rty;
        rty.push_back(1); // First element of the new row
        
        // Compute the intermediate elements
        for (int j = 0; j < rt[i-1].size() - 1; ++j) {
            rty.push_back(rt[i-1][j] + rt[i-1][j+1]);
        }
        
        rty.push_back(1); // Last element of the new row
        rt.push_back(rty);
    }
    
    return rt;
    }
};