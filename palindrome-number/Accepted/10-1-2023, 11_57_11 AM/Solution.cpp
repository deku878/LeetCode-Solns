// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int s) {
        string x=to_string(s);
        string p=x;
        reverse(x.begin(),x.end());
        if(p==x){
            return true;
        }
        else{
            return false;
        }
    }
};