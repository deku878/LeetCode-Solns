// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
        int findDays(vector<int>& weights, int capacity){
        int Day = 1,load = 0;
        for(int i = 0;i<weights.size();i++){
            if(weights[i] + load > capacity){
                Day += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return Day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 1e9;
        while(low <= high){
            int mid = (low + high)/2;
            int noOfDays = findDays(weights,mid);
            if(noOfDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};