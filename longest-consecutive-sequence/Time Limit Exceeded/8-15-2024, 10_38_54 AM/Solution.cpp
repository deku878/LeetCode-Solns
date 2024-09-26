// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        auto iu=st.begin();
        int ko=*iu;
        int ans=1;
        int maxans=1;
        iu++;
        for(auto it=iu;it!=st.end();it++){
            int kl=*it;
            if(ko+1==kl){
                ans++;
                maxans=max(maxans,ans);
                ko+=1;
            }
            else{
                maxans=max(maxans,ans);
                ko=*it;
                ans=1;
            }
            maxans=max(maxans,ans);
        }
        return maxans;
    }
};