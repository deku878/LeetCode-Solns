// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>real;
        if(intervals.size()==0){
            return real;
        }
        real.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(real[j][1]>=intervals[i][0]){
                real[j][0]=min(real[j][0],intervals[i][0]);
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