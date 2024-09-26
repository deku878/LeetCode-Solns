// https://leetcode.com/problems/remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int>pq;
        for(int i=0;i<p.size();i++){
            pq.push(p[i]);
        }
        while(k--){
            int j=pq.top();
            pq.pop();
            pq.push((j+1)/2);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};