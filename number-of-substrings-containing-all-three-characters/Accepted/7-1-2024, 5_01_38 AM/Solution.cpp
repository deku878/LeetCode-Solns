// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        map<char,int>mp;
        int cnt=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()==3){
                cnt+=s.size()-j;
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};