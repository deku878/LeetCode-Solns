// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0;
        int cos=0;
        int t=0;
        int s=0;
        for(int i=0;i<gas.size();i++){
            tot+=gas[i];
            cos+=cost[i];
        }
        if(tot<cos){
            return -1;
        }
        for(int i=0;i<gas.size();i++){
            t+=gas[i]-cost[i];
            if(t<0){
                t=0;
                s=i+1;
            }
        }
        return s;
    }
};