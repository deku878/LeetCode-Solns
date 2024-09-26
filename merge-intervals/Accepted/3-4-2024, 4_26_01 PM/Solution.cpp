// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>real;
        real.push_back(intervals[0]);
        long long int j=0;
        for(int i=1;i<intervals.size();i++){
            if(real[j][1]>=intervals[i][0]){
                real[j][1]=max(real[j][1],intervals[i][1]);
            }
            else{
                j++;
                real.push_back(intervals[i]);
            }
        }
        return real;
    }
};