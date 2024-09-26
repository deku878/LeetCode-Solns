// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        
        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.empty() && right.empty()) {
            return 0; // Both heaps are empty
        }
        
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top(); // Median will always be in the left heap
        }
    }
};