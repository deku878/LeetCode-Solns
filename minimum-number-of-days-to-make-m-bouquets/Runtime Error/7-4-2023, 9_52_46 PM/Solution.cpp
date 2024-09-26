// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k,int days){
        int count=0;
        int noofB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<= days){
                count++;
            }
            else{
                noofB+=(count)/k;
                count=0;
            }
        }
        noofB+=(count)/k;
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=*min_element(bloomDay.begin(), bloomDay.end());
        int end=*max_element(bloomDay.begin(), bloomDay.end());
        if(m*k>bloomDay.size()){
            return -1;
        }
        else{
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(bloomDay, m, k,mid)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }}
        return start;
    }
};