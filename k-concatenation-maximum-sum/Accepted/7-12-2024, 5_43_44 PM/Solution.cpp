// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        //if k=1;
        //we dont have to do anything directly find the kadanes
        //if sum>0
        //we have to basically take the kadanes of first two
        //if sum<0
        //we have to take the kadanes of first two+sum*(k-2) of the rest
        long long int mod=1e9+7;
        long long int sum1=0;
        for(int i=0;i<arr.size();i++){
            sum1+=arr[i];
        }
        if(k==1){
            long long int sum=0,maxsum=0;
            for(int i=0;i<arr.size();i++){
                if(sum+arr[i]<0){
                    maxsum=max(maxsum,sum);
                    sum=0;
                }
                else{
                    sum+=arr[i];
                    maxsum=max(maxsum,sum);
                }
            }
            return maxsum%mod;
        }
        else if(sum1>0){
            long long int sum=0,maxsum=0;
            vector<int>a;
            for(int i=0;i<arr.size();i++){
                a.push_back(arr[i]);
            }
            for(int i=0;i<arr.size();i++){
                a.push_back(arr[i]);
            }
            for(int i=0;i<a.size();i++){
                 if(sum+a[i]<0){
                    maxsum=max(maxsum,sum);
                    sum=0;
                 }
                 else{
                    sum+=a[i];
                    maxsum=max(maxsum,sum);
                }
            }
            return (maxsum+(k-2)*(sum1))%mod;
        }
         long long int sum=0,maxsum=0;
            vector<int>a;
            for(int i=0;i<arr.size();i++){
                a.push_back(arr[i]);
            }
            for(int i=0;i<arr.size();i++){
                a.push_back(arr[i]);
            }
            for(int i=0;i<a.size();i++){
                 if(sum+a[i]<0){
                    maxsum=max(maxsum,sum);
                    sum=0;
                 }
                 else{
                    sum+=a[i];
                    maxsum=max(maxsum,sum);
                }
            }
            return maxsum%mod;
    }
};