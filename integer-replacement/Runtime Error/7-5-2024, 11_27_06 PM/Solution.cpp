// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
                int cnt = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                // Handling the special case for n == 3 to avoid unnecessary steps
                if (n == 3) {
                    cnt += 2; // 3 -> 2 -> 1
                    break;
                }
                // Check which is better: increment or decrement
                if ((n + 1) % 4 == 0) {
                    n++;
                } else {
                    n--;
                }
            }
            cnt++;
        }
        return cnt;

    }
};