// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxarea=INT_MIN;
        while(i<j){
            maxarea=max(maxarea,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
            else if(height[j]==height[i]){
                i++;
                j--;
            }
        }
        return maxarea;
    }
};