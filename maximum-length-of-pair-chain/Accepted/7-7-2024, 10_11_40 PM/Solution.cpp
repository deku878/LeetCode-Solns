// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>lc(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    lc[i]=max(lc[i],lc[j]+1);
                }
            }
        }
        sort(lc.begin(),lc.end());
        return lc[lc.size()-1];
    }
};