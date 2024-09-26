// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n=s.size(),sum=0,maxval,level;
        maxval=INT_MIN;
        sort(s.begin(),s.end());
        if(s[s.size()-1]<=0){
            return 0;
        }
        for(int i=0;i<n;i++){
            sum=0;
            level=1;
            for(int j=i;j<n;j++){
                sum+=(level)*(s[j]);
                level++;
            }
            maxval=max(maxval,sum);
        }
        return maxval;
    }
};