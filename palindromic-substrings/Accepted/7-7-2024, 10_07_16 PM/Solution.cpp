// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool ispal(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            //int even substring
            int p=i;
            int j=i+1;
            while(p>=0 and j<s.size()){
                if(ispal(s,p,j)){
                    cnt++;
                }
                else{
                    break;
                }
                p--;
                j++;
            }
            //odd substrings
            p=i;
            j=i;
            while(p>=0 and j<s.size()){
                if(ispal(s,p,j)){
                    cnt++;
                }
                else{
                    break;
                }
                p--;
                j++;
            }
        }
        return cnt;
    }
};