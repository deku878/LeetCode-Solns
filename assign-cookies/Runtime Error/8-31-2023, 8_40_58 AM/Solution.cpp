// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=s[s.size()-1];
        int lw=0;
        for(int i=0;i<g.size();i++){
            if(ans>=g[i]){
                lw++;
            }
        }
        return lw;
    }
};