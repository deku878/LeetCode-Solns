// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
private:
priority_queue<int>pq,pq1;
int ans=0;
int K;
vector<int>x;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            x.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        x.push_back(val);
        for(int i=0;i<x.size();i++){
            pq.push(x[i]);
        }
        int y=K;
        while(K--){
            ans=pq.top();
            pq.pop();
        }
        K=y;
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */