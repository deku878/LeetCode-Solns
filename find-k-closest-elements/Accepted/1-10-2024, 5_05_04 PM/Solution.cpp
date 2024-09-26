// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<pair<int,int>>vc;
        for(int i=0;i<a.size();i++){
            vc.push_back({abs(x-a[i]),a[i]});
        }
        sort(vc.begin(),vc.end());
        vector<int>y;
        for(int i=0;i<k;i++){
            y.push_back(vc[i].second);
        }
        sort(y.begin(),y.end());
        return y;
    }
};