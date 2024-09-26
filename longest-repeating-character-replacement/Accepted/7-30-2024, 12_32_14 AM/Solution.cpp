// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int maxm = 0;  // Maximum frequency of any character in the current window
        int j = 0;     // Start of the sliding window
        int ans = 0;   // Result, maximum length of the substring found
        
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            maxm = max(maxm, mp[s[i]]);  // Update max frequency in the current window
            
            // If the current window size minus the most frequent character count is greater than k, shrink the window
            if ((i - j + 1 - maxm) > k) {
                mp[s[j]]--;  // Remove the start character from the count
                j++;         // Shrink the window from the start
            }
            
            // Calculate the max length of the window
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};
