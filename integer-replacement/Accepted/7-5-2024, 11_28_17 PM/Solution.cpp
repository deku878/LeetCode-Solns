// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        long long int cnt = 0;
        long long int u=n;
        while (u > 1) {
            if (u % 2 == 0) {
                u /= 2;
            } else {
                // Handling the special case for n == 3 to avoid unnecessary steps
                if (u == 3) {
                    cnt += 2; // 3 -> 2 -> 1
                    break;
                }
                // Check which is better: increment or decrement
                if ((u + 1) % 4 == 0) {
                    u++;
                } else {
                    u--;
                }
            }
            cnt++;
        }
        return cnt;

    }
};