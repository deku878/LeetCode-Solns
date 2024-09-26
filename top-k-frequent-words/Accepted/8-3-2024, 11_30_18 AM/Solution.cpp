// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int ko=words.size();
        vector<string>adj[ko];
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto m:mp){
            adj[m.second].push_back(m.first);
        }
        vector<string>res;
        int cnt=0;
        bool check=true;
        for(int i=ko-1;i>=0;i--){
            vector<string>lmao=adj[i];
            cout<<lmao.size()<<endl;
            if(lmao.size()!=0){
                
                sort(lmao.begin(),lmao.end());
                for(int j=0;j<lmao.size();j++){
                    res.push_back(lmao[j]);
                    cnt++;
                    if(cnt==k){
                        check=false;
                        break;
                    }
                }
            }
            if(!check){
                break;
            }
        }
        return res;
    }
};