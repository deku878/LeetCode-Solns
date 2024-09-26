// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        vector<int>cnt(26,0);
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        vector<int>x;
        int sum=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            bool check=true;
            for(auto m:mp){
                if(cnt[m.first-'a']!=m.second){
                    check=false;
                    break;
                }
            }
            if(check){
                x.push_back(i+1-sum);
                cout<<i+1<<endl;
                sum=i+1;}
        }
        return x;
    }
};