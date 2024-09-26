// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left!=NULL and root->right!=NULL){
            return (root->val>root->left->val) and (root->val<root->right->val);
        }
        if(root->left==NULL){
            return root->val>root->left->val;
        }
        if(root->right==NULL){
            return root->val<root->right->val;
        }
        return isValidBST(root->left) and isValidBST(root->right);
    }
};