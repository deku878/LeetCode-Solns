// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        vector<vector<int>>d;
        if(numrows>1){
        vector<int>a={1};
        vector<int>b={1,1};
        d.push_back(a);
        d.push_back(b);
        numrows-=2;
        while(numrows>0){
        vector<int>c={1};
        for(int i=0;i<b.size()-1;i++){
            c.push_back(b[i]+b[i+1]);
        }
        c.push_back(1);
        d.push_back(c);
        b=c;
        numrows--;
        }}
        else{
           vector<int>a={1};
           d.push_back(a);
        }
        return d;
    }
};