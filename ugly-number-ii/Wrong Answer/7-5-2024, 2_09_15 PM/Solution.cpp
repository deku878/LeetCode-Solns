// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n,0);
        set<long long int>s;
        s.insert(2);
        s.insert(3);
        s.insert(5);
        ugly[0]=1;
        for(int i=1;i<n;i++){
            auto it=s.begin();
            long long int u=*it;
            ugly[i]=*it;
            s.erase(it);
            s.insert(u*2);
            s.insert(u*3);
            s.insert(u*3);
        }
        return ugly[n-1];
    }
};