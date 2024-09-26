// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            long long int a=pq.top();
            pq.pop();
            long long int b=pq.top();
            pq.pop();
            pq.push(a-b);
        }
        return pq.top();
    }
};