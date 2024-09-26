// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>x;
        int i=0;
        int j=0;
        while(i<m and j<n){
            if(nums1[i]<nums2[j]){
                x.push_back(nums1[i]);
                i++;
            }
            else{
                x.push_back(nums2[j]);
                j++;
            }
        }
        if(i>=m and j<n){
            while(j<n){
                x.push_back(nums2[j]);
                j++;
            }
        }
        else if(i<m and j>=n){
            while(i<m){
                x.push_back(nums1[i]);
                i++;
            }
        }
        nums1=x;
        nums2=x;
    }
};