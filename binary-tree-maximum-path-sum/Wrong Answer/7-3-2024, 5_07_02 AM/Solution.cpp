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
int maxm=INT_MIN;
public:
    int maxs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int val=root->val;
        int left=maxs(root->left);
        int right=maxs(root->right);
        maxm=max({maxm,val,val+max(maxs(root->left),0)+max(maxs(root->right),0)});
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        maxs(root);
        return maxm;
    }
};