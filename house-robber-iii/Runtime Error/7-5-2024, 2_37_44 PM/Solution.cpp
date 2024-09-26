// https://leetcode.com/problems/house-robber-iii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int>vals;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                sum+=x->val;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            vals.push_back(sum);
        }
                vector<int>nums=vals;
        int n=nums.size();
        vector<int>dp(n,0);

        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};