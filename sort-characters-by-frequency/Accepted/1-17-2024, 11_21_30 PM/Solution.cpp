// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>vc;
        for(int i=0;i<s.size();i++){
            vc.push_back({mp[s[i]],s[i]});
        }
        sort(vc.begin(),vc.end());
        string h="";
        reverse(vc.begin(),vc.end());
        for(int i=0;i<vc.size();i++){
            h+=vc[i].second;
        }
        return h;
    }
};