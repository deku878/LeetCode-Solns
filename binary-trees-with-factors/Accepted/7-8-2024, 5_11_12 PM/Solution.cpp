// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size() ;
        long long ret = 0 ;
        int M = 1e9 + 7 ;
        unordered_map<int, long>dp ;  
        sort(arr.begin(), arr.end()) ;
        for(int i = 0; i < n; i++){
            dp[arr[i]] = 1 ;
            for(int j = 0; j < i; j++){
                if(arr[i]%arr[j]== 0 &&  dp.count(arr[i]/arr[j]) ){
                    dp[arr[i]] = dp[arr[i]] + dp[arr[j]] * dp[arr[i]/arr[j]] ;
                    dp[arr[i]] %= M ;
                }
            }
        }
        for(auto& d : dp){
            ret = (ret + d.second) % M ;
        }
        
        return ret ;
    }
};