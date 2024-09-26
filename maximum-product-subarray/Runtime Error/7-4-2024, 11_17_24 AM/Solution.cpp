// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int max_curr=a[0];
        int min_curr=a[0];
        int res=INT_MIN;
        res=max({max_curr,min_curr,res});
        for(int i=1;i<a.size();i++){
            int dummy=max_curr;
            max_curr=max({min_curr*a[i],a[i],max_curr*a[i]});
            min_curr=min({dummy*a[i],min_curr*a[i],a[i]});
            res=max({max_curr,min_curr,res});
        }
        return res;
    }
};