// https://leetcode.com/problems/distribute-elements-into-two-arrays-i

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a.back()>b.back()){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        vector<int>c;
        for(int i=0;i<a.size();i++){
            c.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++){
            c.push_back(b[i]);
        }
        return c;
    }
};