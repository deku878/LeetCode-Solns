// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt=0,cnt1=0;
        int cntele=-1;
        int cntel=-1;
        for(int i=0;i<nums.size();i++){
            if(cntele==nums[i]){
                cnt++;
            }
            if(cntel==nums[i]){
                cnt1++;
            }
            if(cnt==0 and cntel!=nums[i]){
                cnt=1;
                cntele=nums[i];
            }
            if(cnt1==0 and cntele!=nums[i]){
                cnt1=1;
                cntel=nums[i];
            }
            if(cntele!=nums[i] and cnt!=0){
                cnt--;
            }
            if(cntel!=nums[i] and cnt1!=0){
                cnt1--;
            }
        }
        int res1=0;
        int res2=0;
        for(int i=0;i<nums.size();i++){
            if(cntele==nums[i]){
                res1++;
            }
            if(cntel==nums[i]){
                res2++;
            }
        }
        vector<int>op;
        cout<<cntele<<" "<<cntel<<endl;
        if(res1>(nums.size())/3){
            op.push_back(cntele);
        }
        if(res2>(nums.size())/3){
            op.push_back(cntel);
        }
        return op;
    }
};