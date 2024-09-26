// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n=arr.size(),sum=0,maxv=INT_MIN,level;
        sort(arr.begin(),arr.end());

        if(arr[n-1]<=0){
            return sum;
        }

        for(int i=0;i<n;i++){
            sum=0;
            level=1;
            for(int j=i;j<n;j++){
                sum+=(arr[j]*level);
                level++;
            }
            maxv=max(sum,maxv);
        }

        return maxv;
  
    }

};