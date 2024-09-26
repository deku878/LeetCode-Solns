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
            res.push_back(ty[0]);
            return ty[0];
        }
        while(i<a.size()){
            if(sum+a[i]>0){
                res.push_back(a[i]);
                sum+=a[i];
                if(sum+a[i]>maxsum){
                maxsum=max(sum,maxsum);
                ans=res;}
            }
            else{
                res.clear();
                sum=0;
            }
            i++;
        }
        return maxsum;
    }
};