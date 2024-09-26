// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    vector<int> rank, parent;
    
    int findpar(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findpar(parent[x]);
    }
    
    void union1(int x, int y) {
        int p1 = findpar(x);
        int p2 = findpar(y);
        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p2] < rank[p1]) {
            parent[p2] = p1;
        } else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            string x = equations[i];
            if (x[1] == '=') {
                int p1 = findpar(x[0] - 'a');
                int p2 = findpar(x[3] - 'a');
                if (p1 != p2) {
                    union1(p1, p2);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            string x = equations[i];
            if (x[1] == '!') {
                int p1 = findpar(x[0] - 'a');
                int p2 = findpar(x[3] - 'a');
                if (p1 == p2) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
