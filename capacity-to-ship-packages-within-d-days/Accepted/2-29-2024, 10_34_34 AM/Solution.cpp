// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool checker(vector<int>&w,int days,int mid){
        long long int c=0;
        long long int res=1;
        for(int i=0;i<w.size();i++){
            if(c+w[i]<=mid){
                c+=w[i];
            }
            else{
                res++;
                if(w[i]>mid){
                    return false;
                }
                c=w[i];
            }
            if(res>days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) {
        long long int lo=1;
        long long int sum=0;
        for(int i=0;i<w.size();i++){
            sum+=w[i];
        }
        long long int hi=sum;
        long long int ans=-1;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(checker(w,days,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};