// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
private:
 priority_queue<int, vector<int>, greater<int>> pq; // min-heap
int ans=0;
int K;
vector<int>x;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (pq.size() < K) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */