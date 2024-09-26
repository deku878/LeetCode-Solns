// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int colNum) {
       string res ="";
        while(colNum > 0){
            colNum--;
            res = char(colNum % 26 + 'A') + res;
            colNum /= 26;
        }
        return res;

    }
};