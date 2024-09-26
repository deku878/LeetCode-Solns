// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>vc;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            vector<int>c(3);
            int target=nums[i];
            if(i>0 and nums[i]==nums[i-1]){
                    continue;
                }
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(target+nums[l]+nums[r]<0){
                    l++;
                }
                 else if(target+nums[l]+nums[r]>0){
                    r--;
                }
                else{
                    c[0]=(target);
                    c[1]=(nums[l]);
                    c[2]=(nums[r]);
                    vc.push_back(c);
                    l++;
                    while(nums[l]==nums[l-1] and l<r){
                        l++;
                    } 
                }
            }
        }
        return vc;
    }
};