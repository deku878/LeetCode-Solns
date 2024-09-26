// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos(n,1),neg(n,1);
        vector<int>dp(n,1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if((nums[i]-nums[j])>0){
                    pos[i]=max(1+neg[j],pos[i]);
                }
                else{
                    neg[i]=max(1+pos[j],neg[i]);
                }
            }
            dp[i]=max({dp[i],pos[i],neg[i]});
        }
        for(int i=0;i<n;i++){
            cout<<pos[i]<<" ";
        }
        cout<<endl;
           for(int i=0;i<n;i++){
            cout<<neg[i]<<" ";
        }
        cout<<endl;
         for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return dp[n-1];
    }
};