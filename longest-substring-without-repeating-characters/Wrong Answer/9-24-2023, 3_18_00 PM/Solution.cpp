// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        long long int count1=0;
        long long int rcount=INT_MIN;
         map<char,long long int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                mp[s[i]]++;
                count1++;
            }
            else{
                mp.clear();
                rcount=max(rcount,count1);
                mp[s[i]]++;
                count1=1;
            }
             rcount=max(rcount,count1);
        }
        cout<<count1;
        return rcount;
    }
};