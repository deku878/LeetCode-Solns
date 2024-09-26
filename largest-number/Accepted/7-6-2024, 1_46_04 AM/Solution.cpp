// https://leetcode.com/problems/largest-number

class Solution {
public:
    static bool cmp(const string &s, const string &t) {
        return (s + t) > (t + s);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> x;
        int n = nums.size();


        for (int i = 0; i < n; i++) {
            x.push_back(to_string(nums[i]));
        }
        sort(x.begin(), x.end(), cmp);
        if (x[0] == "0") return "0";

        string u = "";
        for (int i = 0; i < n; i++) {
            u += x[i];
        }

        return u;
    }
};
