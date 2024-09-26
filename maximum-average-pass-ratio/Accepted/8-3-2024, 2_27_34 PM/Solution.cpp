// https://leetcode.com/problems/maximum-average-pass-ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<classes.size();i++){
            int pass=classes[i][0];
            int ko=classes[i][1];
            double il=double(pass+1)/double(ko+1)-double(pass)/double(ko);
            pq.push({il,{pass,ko}});
        }
        while(extraStudents--){
            int pass=pq.top().second.first;
            int ko=pq.top().second.second;
            pass++;
            ko++;
            pq.pop();
            double op=double(pass+1)/double(ko+1)-double(pass)/double(ko);
            pq.push({op,{pass,ko}});
        }
        double res=0;
        while(!pq.empty()){
            res+=double(pq.top().second.first)/double(pq.top().second.second);
            pq.pop();
        }
        return res/double(classes.size());
    }
};