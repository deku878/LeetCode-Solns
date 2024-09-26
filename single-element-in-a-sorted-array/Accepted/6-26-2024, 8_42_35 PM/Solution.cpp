// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        //brute is to take xor lol
        if(a.size()==1){
            return a[0];
        }
        int lo=1;
        int hi=a.size()-2;
        if(a[0]!=a[1]){
            return a[0];
        }
        else if(a[a.size()-1]!=a[a.size()-2]){
            return a[a.size()-1];
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(a[mid]!=a[mid-1] and a[mid]!=a[mid+1]){
                return a[mid];
            }
            //even hai
        
            else if((mid%2==0 and a[mid]==a[mid-1])  or  (mid%2==1 and a[mid]==a[mid+1])){
                hi=mid-1;
            }

            else{
                lo=mid+1;
            }
        }
        return -1;
    }
};