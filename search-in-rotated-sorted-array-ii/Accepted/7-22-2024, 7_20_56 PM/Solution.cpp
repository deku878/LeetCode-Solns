// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& a, int target) {
        int lo=0;
        int hi=a.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(a[mid]==target){
                return true;
            }
            if(a[lo]==a[mid] and a[mid]==a[hi]){
                lo++;
                hi--;
            }
            else if(a[lo]<=a[mid]){
                if(a[lo]<=target and target<=a[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                if(a[mid]<=target and target<=a[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return false;
    }
};