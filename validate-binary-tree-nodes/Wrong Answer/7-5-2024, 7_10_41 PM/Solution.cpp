// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    vector<int> parent, rank;

    int findpar(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findpar(parent[x]);
    }

    void union1(int x, int y) {
        int p1 = findpar(x);
        int p2 = findpar(y);
        
        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
   
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            if (l[i] != -1) {
                if (findpar(l[i]) == findpar(i)) {
                    return false;
                }
                union1(i, l[i]);
            }
            if (r[i] != -1) {
                if (findpar(r[i]) == findpar(i)) {
                    return false;
                }
                union1(i, r[i]);
            }
        }
        
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                components++;
            }
        }
        
        return components == 1;
    }
};
