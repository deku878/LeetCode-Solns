// https://leetcode.com/problems/delete-columns-to-make-sorted-iii


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //ghi def abc
        //babca bbazb
        int ans=INT_MAX;
        for(int i=0;i<strs.size();i++){
            string x=strs[i];
            vector<char>lis;
            for(int j=0;j<x.size();j++){
                auto it=lower_bound(lis.begin(),lis.end(),x[j]);
                if(it==lis.end()){
                    lis.push_back(x[j]);
                }
                else{
                    int idx=lower_bound(lis.begin(),lis.end(),x[j])-lis.begin();
                    lis[idx]=x[j];
                }
            }
            if(ans>lis.size()){
                ans=lis.size();
            }
        }
        return strs[0].size()-ans;
    }
};