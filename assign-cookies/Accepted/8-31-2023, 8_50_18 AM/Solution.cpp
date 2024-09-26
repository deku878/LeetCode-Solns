// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size()!=0){
        int j=0;
        int lw=0;
        int i=0;
        while(i<g.size() and j<s.size()){
            if(s[j]>=g[i]){
                lw++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return lw;
        }
        else{
            return 0;
        }
    }
};