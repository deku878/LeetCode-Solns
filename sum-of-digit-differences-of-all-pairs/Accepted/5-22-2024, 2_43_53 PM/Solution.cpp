// https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
 vector<string> p;
        for (int i = 0; i < nums.size(); i++) {
            p.push_back(to_string(nums[i]));
        }

        // Array to handle digit counts for each position, max digits in an int is 10
        const int maxDigits = 10;
        const int digitRange = 10;
        long long count[10][10] = {0};

        // Populate the counts of digits at each position
        for (const string &x : p) {
            for (int j = 0; j < x.size(); j++) {
                count[j][x[j] - '0']++;
            }
        }

        long long ans = 0;

        // Calculate the answer
        for (const string &y : p) {
            for (int j = 0; j < y.size(); j++) {
                int digit = y[j] - '0';
                long long countLess = 0, countGreater = 0,counteq=0;

                // Count how many digits are less than and greater than the current digit at the same position
                for (int k = 0; k < digit; k++) {
                    countLess += count[j][k];
                }
                for (int k = digit + 1; k < digitRange; k++) {
                    countGreater += count[j][k];
                }
                counteq=count[j][digit];
                // Update ans with the current digit difference contributions
                ans +=(countLess+countGreater)*(counteq);

                // Decrement the current digit count as we process it
                count[j][digit]=0;
            }
        }

        return ans;
    }
};