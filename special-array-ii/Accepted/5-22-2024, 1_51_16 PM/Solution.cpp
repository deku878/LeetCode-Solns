// https://leetcode.com/problems/special-array-ii

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>pref(nums.size(),0);
        pref[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                pref[i]=pref[i-1]+1;
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        vector<bool>h;
        for(int i=0;i<queries.size();i++){
            vector<int>c=queries[i];
            long long int x=c[0];
            long long int y=c[1];
            if(pref[y]-pref[x]!=0){
                h.push_back(false);
            }
            else{
            h.push_back(true);
            }
        }
        return h;
    }
};