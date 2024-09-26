// https://leetcode.com/problems/merge-sorted-array

#include <bits/stdc++.h>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        sort(nums2.begin(),nums2.end());
        long long int j=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                nums1[i]=nums2[j];
                j++;
            }
            if(j==n){
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};