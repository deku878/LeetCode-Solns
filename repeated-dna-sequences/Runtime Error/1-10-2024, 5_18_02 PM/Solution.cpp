// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,long long int>mp;
            vector<string>x;
            for(int i=0;i<s.size()-9;i++){
                string p=s.substr(i,10);
                mp[p]++;
            }
            for(auto m:mp){
                if(m.second>1){
                    x.push_back(m.first);
                }
            }
            return x;
    }
};