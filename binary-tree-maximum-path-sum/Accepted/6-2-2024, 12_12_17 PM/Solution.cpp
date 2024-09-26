// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int max_sum=INT_MIN;
    int maxr(TreeNode* root){
       if(root==NULL){
        return 0;
       }
       int l=max(0,maxr(root->left));
       int r=max(0,maxr(root->right));
       int n=root->val+l+r;
       max_sum=max(max_sum,n);
       return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        maxr(root);
        return max_sum;
    }
};