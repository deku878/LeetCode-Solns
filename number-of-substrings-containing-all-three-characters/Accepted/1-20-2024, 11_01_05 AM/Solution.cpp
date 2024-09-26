// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
        int k=0;
            map<char,int>mp;
            int j=0;
            while(j<s.size()){
                mp[s[j]]++;
                while(mp.size()>=3){
                    mp[s[k]]--;
                    if(mp[s[k]]<=0){
                        mp.erase(s[k]);
                    }
                    count+=n-j;
                    k++;
                }
                j++;
            }
        return count;
    }
};