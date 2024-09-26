// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size()!=0){
        int ans=s[s.size()-1];
        int lw=0;
        for(int i=0;i<g.size();i++){
            if(ans>=g[i]){
                lw++;
            }
        }
        if(lw>s.size()){
        return s.size();}
        else{
            return lw;
        }}
        else{
            return 0;
        }
    }
};