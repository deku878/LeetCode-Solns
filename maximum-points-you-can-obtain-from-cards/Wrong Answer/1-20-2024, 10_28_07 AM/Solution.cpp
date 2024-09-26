// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& a,int k) {
        int i=0;
        int j=a.size()-1;
        int sum=0;
        int count=0;
        while(i<=j and count<k){
            if(a[i]>a[j]){
                sum+=a[i];
                i++;
            }
            else{
                sum+=a[j];
                j--;
            
        }
        count++;
        }
        return sum;
    }
};