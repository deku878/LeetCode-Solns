// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int maxsum=0;
        int i=0;
        int sum=0;
        vector<int>res,ans;
        vector<int>ty=a;
        sort(ty.begin(),ty.end(),greater<int>());
        if(ty[0]<=0){
            return ty[0];
        }
        while(i<a.size()){
            if(sum+a[i]>0){
                sum+=a[i];
                if(sum+a[i]>maxsum){
                maxsum=max(sum,maxsum);
                ans=res;}
            }
            else{
                sum=0;
            }
            i++;
        }
        return maxsum;
    }
};