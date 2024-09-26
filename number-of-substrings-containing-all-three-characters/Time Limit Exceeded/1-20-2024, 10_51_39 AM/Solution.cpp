// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            map<char,int>mp;
            int j=i;
            while(j<s.size()){
                mp[s[j]]++;
                if(mp.size()==3){
                    count+=n-j;
                    break;
                }
                j++;
            }
            
        }
        return count;
    }
};