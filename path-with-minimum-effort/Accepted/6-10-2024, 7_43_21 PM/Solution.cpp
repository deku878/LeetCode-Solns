// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == n-1 && y == m-1) return diff;

            for(int i=0; i<4; ++i){
                int nr = x+delrow[i];
                int nc = y+delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort = max(abs(heights[x][y] - heights[nr][nc]), diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
