// https://leetcode.com/problems/powx-n

class Solution {
public:
double helper(double x, long long n) {
    if (n == 0) {
        return 1.0;
    }
    if (n < 0) {
        return 1.0 / helper(x, -n);
    }
    double p = helper(x, n / 2);
    if (n % 2 == 0) {
        return p * p;
    } else {
        return p * p * x;
    }
}

double myPow(double x, int n) {
    return helper(x, n);
}
};