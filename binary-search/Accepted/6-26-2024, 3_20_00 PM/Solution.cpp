// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& a, int target) {
        int real=-1;
        int lo=0;
        int hi=a.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(a[mid]>target){
                hi=mid-1;
            }
            else if(a[mid]<target){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        return real;
    }
};