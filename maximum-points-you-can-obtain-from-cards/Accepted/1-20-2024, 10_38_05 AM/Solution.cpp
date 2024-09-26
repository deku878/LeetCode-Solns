// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& a,int k) {
        int n=a.size();
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=a[0];
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i-1]+a[i];
        }
        reverse(a.begin(),a.end());
        suff[0]=a[0];
        for(int i=1;i<n;i++){
            suff[i]=suff[i-1]+a[i];
        }
        int sum=pref[k-1];
        for(int i=1;i<k;i++){
            sum=max(sum,pref[k-i-1]+suff[i-1]);
        }
        sum=max(sum,suff[k-1]);
        return sum;
    }
};