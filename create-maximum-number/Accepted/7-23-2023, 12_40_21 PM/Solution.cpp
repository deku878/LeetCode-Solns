// https://leetcode.com/problems/create-maximum-number

class Solution {
public:
vector<int>greatestsubsequence(vector<int> &nums,int k){
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(ans.size()>0 && ans.back()<nums[i] && ((k-ans.size())<(n-i))) // If true, then pop out the last element
            ans.pop_back();
            if(ans.size()<k)ans.push_back(nums[i]); 

    }
    return ans;
}
void pop_front(vector<int> &p){
    if(p.size()>0){
        p.erase(p.begin());
    }
}
vector<int>merge(vector<int>&num1,vector<int>&num2,int k){
    vector<int>temp1;
    for(int i=0;i<k;i++){
        vector<int>temp=max(num1,num2);
        int fr=temp.front();
        if(num1>num2){
            pop_front(num1);
        }
        else{
            pop_front(num2);
        }
        temp1.push_back(fr);
    }
    return temp1;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>res;
        for(int i=0;i<=k;i++){
            int j=k-i;
            if(i>nums1.size() or j>nums2.size()){
                continue;
            }
             vector<int>max1=greatestsubsequence(nums1,i);
            vector<int>max2=greatestsubsequence(nums2,j);
            vector<int>temp=merge(max1,max2,k);
                res=max(res,temp);
        }
        return res;
    }
};