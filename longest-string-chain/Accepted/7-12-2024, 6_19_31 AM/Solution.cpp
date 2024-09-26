// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int longestChain = 1;

        for (const string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp[predecessor] + 1);
            }
            longestChain = max(longestChain, dp[word]);
        }

        return longestChain;
    }
};