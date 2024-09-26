// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    static bool comp(const vector<int>&u,const vector<int>&v){
        return u[1]>v[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int totalUnits=0;
        for(auto& box:boxTypes){
            int numBoxes=min(truckSize,box[0]);
            totalUnits+=numBoxes*box[1];
            truckSize-=numBoxes;
        }
        return totalUnits;
    }
};