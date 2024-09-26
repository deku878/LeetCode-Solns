// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& a, int x) {
        int lo=0;
        int hi=a.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(x==a[mid]){
                return mid;
            }
            if(a[lo]<=a[mid]){
                if(a[lo]<=x and x<a[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                if(a[mid]<x and x<=a[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};