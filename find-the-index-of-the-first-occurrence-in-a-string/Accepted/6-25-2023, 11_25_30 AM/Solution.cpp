// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int p=haystack.length();
        int q=needle.length();
        vector<int>c;
        for(int i=0;i<=(p-q);i++){
            bool check=true;
            for(int j=0;j<q;j++){
                if(haystack[i+j]!=needle[j]){
                    check=false;
                    break;
                }
            }
            if(check){
                c.push_back(i);
            }
        }
        if(!c.empty()){
        sort(c.begin(),c.end());
        return c[0];}
        else{
        return -1;}
    }
};