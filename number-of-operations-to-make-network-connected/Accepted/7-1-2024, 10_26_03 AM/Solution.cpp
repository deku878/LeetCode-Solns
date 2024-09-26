// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
vector<int>rank,parent;
public:
        int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void union1(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if (p1 == p2) {
            return;
        }
        if (rank[p2] < rank[p1]) {
            parent[p2] = p1;
        } else if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extraEdges = 0;
        for (const auto& conn : connections) {
            if (find(conn[0]) == find(conn[1])) {
                extraEdges++;
            } else {
                union1(conn[0], conn[1]);
            }
        }

        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                connectedComponents++;
            }
        }

        if (extraEdges >= connectedComponents - 1) {
            return connectedComponents - 1;
        }
        return -1;
    }

};