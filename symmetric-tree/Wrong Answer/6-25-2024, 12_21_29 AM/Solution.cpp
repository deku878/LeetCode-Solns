// https://leetcode.com/problems/symmetric-tree

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
    bool iss(TreeNode* root,TreeNode*root1){
        if(!root and !root1){
            return true;
        }
        if(!root and root1){
            return false;
        }
        if(root and !root1){
            return false;
        }
        return (root->val==root->val) and iss(root->left,root1->right) and iss(root->right,root1->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL or (!root->left and !root->right)){
            return true;
        }
        return iss(root->left,root->right);
    }
};