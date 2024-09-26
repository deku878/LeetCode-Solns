// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int binarySearch(vector<int>&arr, int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int minIdx(vector<int>&v){
         int l=0;
        int r=v.size()-1;
        int index;
        while(l<=r){
            int mid=(l+r)/2;
            int next=(mid+1)%v.size();
            int prev=(mid+v.size()-1)%v.size();
            if(v[mid]<=v[next] and v[mid]<=v[prev]){
               return mid;
            }
            else{
                if(v[l]<=v[mid]){
                    l=mid+1;
                }
                else if(v[mid]<=v[r]){
                    r=mid-1;
                }
            }
        }
        return 0;}
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int idx = minIdx(nums);
       int st = idx, ed = n-1;
        int ans = binarySearch(nums,st,ed,target);
        if(ans == -1){
            st = 0, ed = idx-1;
            ans = binarySearch(nums,st,ed,target);
        }
        return ans;}
};