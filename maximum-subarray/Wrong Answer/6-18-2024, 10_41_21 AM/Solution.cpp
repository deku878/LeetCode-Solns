// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum=0;
        int realsum=0;
        for(int i=0;i<a.size();i++){
            if(sum+a[i]<0){
                realsum=max(sum,realsum);
                sum=0;
                realsum=max(sum,realsum);
            }
            else{
                sum+=a[i];
                realsum=max(sum,realsum);
            }
            realsum=max(sum,realsum);
        }
    return realsum;
    }
};