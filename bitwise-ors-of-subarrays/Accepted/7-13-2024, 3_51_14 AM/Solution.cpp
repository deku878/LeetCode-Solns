// https://leetcode.com/problems/bitwise-ors-of-subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>s;
        set<int>t;
        for(int i=0;i<arr.size();i++){
            set<int>r;
            r.insert(arr[i]);
            for(int j:t){
                r.insert(arr[i]|j);
            }
            t=r;
            for(int j:t){
                s.insert(j);
            }
        }
        return s.size();
    }
};