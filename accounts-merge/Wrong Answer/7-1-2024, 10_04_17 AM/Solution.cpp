// https://leetcode.com/problems/accounts-merge

class Solution {
public:
vector<int> parent, rank;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void union1(int x_par, int y_par){
    if(rank[x_par] > rank[y_par]){
        parent[y_par] = x_par;
    }
    else if(rank[y_par] > rank[x_par]){
        parent[x_par] = y_par;
    }
    else{
        parent[x_par] = y_par;
        rank[y_par]++;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    parent.resize(accounts.size());
    rank.resize(accounts.size());
    for(int i = 0; i < accounts.size(); i++){
        parent[i] = i;
        rank[i] = 1;
    }
    
    map<string, int> mp;
    for(int i = 0; i < accounts.size(); i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string x = accounts[i][j];
            if(mp.find(x) == mp.end()){
                mp[x] = i;
            }
            else{
                union1(i, mp[x]);
            }
        }
    }
    
    vector<vector<string>> adj(accounts.size());
    for(auto m : mp){
        int n = m.second;
        int np = find(n);
        adj[np].push_back(m.first);
    }
    
    vector<vector<string>> x1;
    for(int i = 0; i < accounts.size(); i++){
        if(adj[i].empty()){
            continue;
        }
        sort(adj[i].begin(), adj[i].end());
        vector<string> x;
        x.push_back(accounts[i][0]);
        for(auto u : adj[i]){
            x.push_back(u);
        }
        x1.push_back(x);
    }
    return x1;
}
};