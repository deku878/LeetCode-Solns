// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    static bool comp(const pair<int,int>& p, const pair<int,int>& q) {
        if (p.first == q.first) return p.second > q.second;
        return p.first < q.first;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>> vc;
        for (int i = 0; i < envelopes.size(); i++) {
            vc.push_back({envelopes[i][0], envelopes[i][1]});
        }
        sort(vc.begin(), vc.end(), comp);

        vector<int> heights;
        for (int i = 0; i < vc.size(); i++) {
            heights.push_back(vc[i].second);
        }

        vector<int> res;
        for (int i = 0; i < heights.size(); i++) {
            auto it = lower_bound(res.begin(), res.end(), heights[i]);
            if (it == res.end()) {
                res.push_back(heights[i]);
            } else {
                *it = heights[i];
            }
        }
        return res.size();
    }
};