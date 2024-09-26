// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //isme boundary create krni hoti hh basically
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int lo=0;
        int hi=nums1.size();
        int sz=(nums1.size()+nums2.size()+1)/2;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int mid2=sz-mid;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(mid-1>=0){
                l1=nums1[mid-1];
            }
            if(mid2-1>=0){
                l2=nums2[mid2-1];
            }
            if(mid>=0 and mid<nums1.size()){
                r1=nums1[mid];
            }
            if(mid2>=0 and mid2<nums2.size()){
                r2=nums2[mid2];
            }
            if(l1<=r2 and l2<=r1){
                if((nums1.size()+nums2.size())%2==0){
                    double median=(max(l1,l2)+min(r1,r2))/2.0;
                    return median;
                }
                else{
                    double median=max(l1,l2);
                    return median;
                }
            }
            if(l1>r2){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return -1;
    }
};