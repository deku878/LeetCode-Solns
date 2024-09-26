// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii

class Solution {
public:
   int maximumLength(string s) {
        map<string,long long int>mp;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
            string x;
            x=s.substr(i,j-i+1);
            mp[x]++;}
        }
        long long int count1=INT_MIN;
        for(auto m:mp){
            if(m.second>=3){
            string h=m.first;
            if(count(h.begin(),h.end(),h[0])==h.size()){
            long long int o=h.size();
            count1=max(count1,o);}}
        }
        if(count1!=INT_MIN){
            return count1;
        }
        return -1;
    }
};