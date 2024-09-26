// https://leetcode.com/problems/count-the-number-of-inversions

#include<bits/stdc++.h>
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1000000007;
        unordered_map<int, int> req;
        const int MAX_INV = 400;
        vector<vector<long long>> dp(n + 1, std::vector<long long>(MAX_INV + 1, 0));
        dp[0][0] = 1;
        for (const auto& r : requirements) {
            req[r[0] + 1] = r[1];
        }

        

        for (int len = 1; len <= n; len++) {
            for (int inv = 0; inv <= MAX_INV; inv++) {
                for (int pos = 0; pos < len; pos++) {
                    int prevInv = inv - pos;
                    if (prevInv >= 0) {
                        dp[len][inv] = (dp[len][inv] + dp[len - 1][prevInv]) % MOD;
                    }
                }
            }

            if (req.find(len) != req.end()) {
                int tInv = req[len];
                for (int inv = 0; inv <= MAX_INV; inv++) {
                    if (inv != tInv) {
                        dp[len][inv] = 0;
                    }
                }
            }
        }

        long long res = 0;
        for (long long cnt : dp[n]) {
            res = (res + cnt) % MOD;
        }

        return res;
    }
};