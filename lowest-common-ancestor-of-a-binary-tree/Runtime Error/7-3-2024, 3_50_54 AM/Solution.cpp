// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p or root==q){
            return root;
        }
        if(p==NULL or q==NULL){
            return root;
        }
        if(root->left==p and root->right==q or root->right==p and root->left==q){
            return root;
        }
        if(lowestCommonAncestor(root->left,p,q)==p or lowestCommonAncestor(root->left,p,q)==q){
            return root->left;
        }
        if(lowestCommonAncestor(root->right,p,q)==p or lowestCommonAncestor(root->right,p,q)==q){
            return root->right;
        }
        return NULL;
    }
};