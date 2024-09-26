// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0;
        int high=nums1.size();
        int l1,l2,r1,r2;
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=(nums1.size()+nums2.size()+1)/2-cut1;
            if (cut1 == 0) {l1 = INT_MIN;} 
            else {
    l1 = nums1[cut1 - 1];}

if (cut2 == 0) {
    l2 = INT_MIN;
} else {
    l2 = nums2[cut2 - 1];
}

if (cut1 == n1) {
    r1 = INT_MAX;
} else {
    r1 = nums1[cut1];
}

if (cut2 == n2) {
    r2 = INT_MAX;
} else {
    r2 = nums2[cut2];
}
if(l1 <= r2 && l2 <= r1)
            {
                if((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else
                {
                    return max(l1/1.0, l2/1.0);
                }
            }
else if(l1 > r2)
            {
                high = cut1 - 1; 
            }
            else
            {
                low = cut1 + 1;
            }

    }
    return 0.0;}
};