// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node

class Solution {
public:
    const int MOD = 1000000007;
    typedef pair<int, int> pii;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> lis(n + 1);

        for (auto& edge : edges) {
            int i = edge[0], j = edge[1], k = edge[2];
            lis[i].push_back({j, k});
            lis[j].push_back({i, k});
        }

        vector<long long> score(n + 1, 0); 
        score[n] = 1;

        vector<int> least(n + 1, numeric_limits<int>::max());
        priority_queue<pii, vector<pii>, greater<pii>> heap; 
        heap.push({0, n}); 

        while (!heap.empty()) {
            int u = heap.top().first;
            int v = heap.top().second;
            heap.pop();

            if (v == 1) {
                continue;
            }

            if (least[v] < u) {
                continue;
            }

            for (auto& edge : lis[v]) {
                int i = edge.first;
                int k = edge.second;
                int temp = u + k;

                if (temp < least[i]) {
                    least[i] = temp;
                    heap.push({temp, i});
                }

                if (u < least[i]) {
                    score[i] = (score[i] + score[v]) % MOD;
                }
            }
        }

        return score[1];
    }
};
