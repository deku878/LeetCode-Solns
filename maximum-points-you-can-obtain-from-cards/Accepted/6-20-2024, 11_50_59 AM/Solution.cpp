// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& ca, int k) {
        int left=0;
        int right=0;
        int li=0;
        int ri=ca.size()-1;
        int maxm=INT_MIN;
        for(int i=0;i<k;i++){
            left+=ca[i];
        }
        maxm=max(maxm,left);
        for(int i=k-1;i>=0;i--){
            left-=ca[i];
            right+=ca[ri];
            ri--;
            maxm=max(maxm,left+right);
        }
        return maxm;
    }
};