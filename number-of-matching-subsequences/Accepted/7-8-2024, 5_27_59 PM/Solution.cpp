// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        map<char,vector<int>>mp;
        int i=0;
        for(auto x:s){
            mp[x].push_back(i++);
        }
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            int latest=-1;
            for(int j=0;j<words[i].size();j++){
                auto it=upper_bound(mp[curr[j]].begin(),mp[curr[j]].end(),latest);
                if(it==mp[curr[j]].end()){
                    break;
                }
                latest=*it;
                if(j==curr.size()-1){
                    count++;
                }
            }
        }
        return count;
    }
};