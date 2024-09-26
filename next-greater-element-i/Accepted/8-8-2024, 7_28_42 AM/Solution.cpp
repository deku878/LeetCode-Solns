// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;   
        }
        vector<int>nge(nums2.size(),0);
        for(int i=nums2.size()-1;i>=0;i--){
            int x=-1;
            while(!st.empty() and st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                x=st.top();
            }
            st.push(nums2[i]);
            nge[i]=x;
        }
        vector<int>nger(nums1.size(),0);
        for(int i=0;i<nger.size();i++){
            nger[i]=nge[mp[nums1[i]]];
        }
        return nger;
    }
};