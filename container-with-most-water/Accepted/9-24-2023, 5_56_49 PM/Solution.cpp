// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        while(i<j){
            int l=height[i];
            int r=height[j];
            int min_h=min(l,r);
            int size1=j-i;
            int curr_area=(min_h)*size1;
            area=max(area,curr_area);
            if(l<r){
                i++;
            }
            else{
                j--;
            }}
        return area;}
};