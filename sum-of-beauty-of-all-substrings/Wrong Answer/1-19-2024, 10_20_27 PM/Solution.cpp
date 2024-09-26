// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            int j=i+1;
            map<char,int>mp;
            int maxm=INT_MIN;
            int minm=INT_MAX;
            mp[s[i]]++;
            while(j<s.size()){
                mp[s[j]]++;
                for(auto m:mp){
                    maxm=max(maxm,m.second);
                    minm=min(minm,m.second);
                }
                if((maxm!=minm)){
                    count+=(maxm-minm);
                }
                j++;
            }
        }
        return count;
    }
};