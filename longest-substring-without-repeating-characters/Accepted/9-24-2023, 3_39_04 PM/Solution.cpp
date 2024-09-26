// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       long long int maxlength=0;
       long long int i=0;
       long long int n=s.size();
       while(i<n){
           vector<bool>vis(256,false);
           long long int j=i;
           while(j<n and vis[s[j]]==false){
               maxlength=max(maxlength,j-i+1);
               vis[s[j]]=true;
               j++;
           }
           vis[s[j]]=false;
           i++;
       }
       return maxlength;
    }
};