// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        //2d integers
        //width and height are larger
        int n=e.size();
        sort(e.begin(),e.end(),cmp);
        vector<int>lis;
        for(int i=0;i<e.size();i++){
            int p=e[i][1];
            int idx=lower_bound(lis.begin(),lis.end(),p)-lis.begin();
            if(idx>=lis.size()){
                lis.push_back(p);
            }
            else{
                lis[idx]=i;
            }
        }
        return lis.size();
    }
};