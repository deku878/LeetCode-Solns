// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        long long int lo=0;
        long long int hi=l.size()-1;
        char ans=l[0];
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(l[mid]>target){
                ans=l[mid];
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};