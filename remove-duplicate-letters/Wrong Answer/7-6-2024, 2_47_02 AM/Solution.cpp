// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<bool>taken(26,0);
        vector<int>lasti(26,0);
        for(int i=0;i<s.size();i++){
            lasti[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            while(result.size()>0 and result.back()>ch and lasti[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            if(!taken[ch-'a']){
            result.push_back(ch);}
            taken[ch-'a']=true;
        }
        return result;
    }
};