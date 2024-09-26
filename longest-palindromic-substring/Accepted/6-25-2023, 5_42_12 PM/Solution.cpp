// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        int max=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(r<n and l>=0 and s[l]==s[r]){
                int curr_l=r-l+1;
                if(curr_l>max){
                    max=curr_l;
                    ans = s.substr(l, curr_l);
                }
                l--;
                r++;
            }
        }
        for(int i=0;i<n;i++){
            int l=i;
            int r=i+1;
            while(r<n and l>=0 and s[l]==s[r]){
                int curr_l=r-l+1;
                if(curr_l>max){
                    max=curr_l;
                    ans = s.substr(l, curr_l);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};