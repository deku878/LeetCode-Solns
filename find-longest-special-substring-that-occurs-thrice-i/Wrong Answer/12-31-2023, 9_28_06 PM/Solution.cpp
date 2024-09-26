// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

class Solution {
public:
    int maximumLength(string s) {
        map<string,long long int>mp;
        for(int i=0;i<s.size();i++){
            string x="";
            for(int j=i;j<s.size();j++){
            x=s.substr(i,j-i+1);
            mp[x]++;}
        }
        long long int count=INT_MIN;
        for(auto m:mp){
            if(m.second>=3){
            string h=m.first;
            long long int o=h.size();
            count=max(count,o);}
        }
        if(count!=INT_MIN){
            return count;
        }
        return -1;
    }
};