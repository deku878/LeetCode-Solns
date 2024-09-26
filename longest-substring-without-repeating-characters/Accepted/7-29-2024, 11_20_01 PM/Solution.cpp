// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mp;
        int maxm = 0; 
        int prev = -1; 
        
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) != 0) {
                
                prev = max(prev, mp[s[i]]);
            }

            mp[s[i]] = i;

            maxm = max(maxm, i - prev);
        }
        
        return maxm;
    }
};