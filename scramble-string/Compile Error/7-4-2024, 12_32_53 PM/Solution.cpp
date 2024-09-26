// https://leetcode.com/problems/scramble-string

class Solution {
public:
   unordered_map<string, bool> mp;

bool rec(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int n = s1.size();
    
    if (s1 == s2) {
        return true;
    }
    
    string res = s1 + "_" + s2;
    if (mp.count(res)) {
        return mp[res];
    }
    
    bool scramble = false;
    for (int i = 1; i < n && !scramble; ++i) {
        // Original conditions included
        if ((rec(s1.substr(0, i), s2.substr(i, n - i)) && rec(s1.substr(i, n - i), s2.substr(0, i))) ||
            (rec(s1.substr(0, i), s2.substr(0, i)) && rec(s1.substr(i, n - i), s2.substr(i, n - i)))||
            ) {
            scramble = true;
        }
    }
    
    return mp[res] = scramble;
}

    bool isScramble(string s1, string s2) {
        mp.clear();
    return rec(s1, s2);
    }
};