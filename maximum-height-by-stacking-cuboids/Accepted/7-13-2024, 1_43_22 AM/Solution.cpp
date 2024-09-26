// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // sort every vector so that height is maximum in everyone
        for (auto &c : cuboids)
        {
            sort(c.begin(), c.end());
        }
        // sorted so that we can use LIS
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            // height of that cuboid
            dp[i] = cuboids[i][2];
            for (int j = 0; j <= i - 1; j++)
            {
                if ((cuboids[i][0] >= cuboids[j][0]) && (cuboids[i][1] >= cuboids[j][1]) && (cuboids[i][2] >= cuboids[j][2]))
                {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;

    }
};