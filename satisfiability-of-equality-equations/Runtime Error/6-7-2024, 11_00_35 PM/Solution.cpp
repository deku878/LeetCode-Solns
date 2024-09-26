// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(auto s:equations){
            if(s[1]=='='){
                Union(s[0]-'0',s[3]-'0');
            }
        }
        for(auto s:equations){
            if(s[1]=='!'){
                int x_parent=find(s[0]-'0');
                int y_parent=find(s[3]-'0');
                if(x_parent==y_parent){
                    return false;
                }
            }
        }
        return true;
    }
};