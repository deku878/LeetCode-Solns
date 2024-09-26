// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int M = 1e9+7;
        long long int ans = 0;
        stack<int> s;
        vector<int> left(arr.size()), right(arr.size());

        // Calculate left
        for(int i = 0; i < arr.size(); i++){
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        // Clear stack
        while(!s.empty()) {
            s.pop();
        }

        // Calculate right
        for(int i = arr.size()-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = (s.empty()) ? arr.size() : s.top();
            s.push(i);
        }

        // Calculate answer
        for(int i = 0; i < arr.size(); i++){
            ans = (ans + (long long)arr[i]*(i-left[i])*(right[i]-i)) % M;
        }

        return (int)ans;
    }
};