// https://leetcode.com/problems/alternating-groups-i

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
       int count=0;
        for(int i=1;i<colors.size()-1;i++){
           if(colors[i-1]!=colors[i] and colors[i]!=colors[i+1] and colors[i-1]==colors[i+1]){
               count++;
           }
       }
       if(colors[colors.size()-2]!=colors[colors.size()-1] and colors[colors.size()-1]!=colors[0] and colors[colors.size()-2]==colors[0]){
           count++;
       }
       if(colors[colors.size()-1]!=colors[0] and colors[1]!=colors[0] and colors[colors.size()-1]==colors[1]){
           count++;
       }
       return count;
    }
};