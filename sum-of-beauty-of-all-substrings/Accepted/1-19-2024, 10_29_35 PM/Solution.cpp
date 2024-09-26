// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            map<char,int>mp;
            
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp.size()==1){
                    count+=0;
                }
                else{
                    int maxm=INT_MIN;
                    int minm=INT_MAX;
                for(auto m:mp){
                    
                    maxm=max(maxm,m.second);
                    minm=min(minm,m.second);
                }
                count+=(maxm-minm);}
            }
        }
        return count;
    }
};