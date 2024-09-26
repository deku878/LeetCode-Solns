// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
             int maxele = INT_MIN;
     int maxidx = -1;
     int n = nums.size();

     for(int i=0;i<n;i++){
        if(maxele < nums[i]){
            maxele = nums[i];
            maxidx = i;
        }
     }

     vector<int> nge(n);
     nge[maxidx] = -1;
     stack<int> st;
     st.push(maxele);

     for(int i=maxidx-1;i>(maxidx-n-1);i--){
        
        int idx = i;
        if(idx<0)
        idx = n+idx;

        if(st.top() > nums[idx]){
            nge[idx] = st.top();
            st.push(nums[idx]);
        }
        else{
            
            while(!st.empty() && st.top() <= nums[idx]){
                st.pop();
            }

            if(st.empty())
            nge[idx] = -1;
            else
            nge[idx] = st.top();

            st.push(nums[idx]);
            

        }
        
     }
     
     return nge;
    }
};