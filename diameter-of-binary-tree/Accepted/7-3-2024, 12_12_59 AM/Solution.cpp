// https://leetcode.com/problems/diameter-of-binary-tree

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
int dia=INT_MIN;
public:
    int ans(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        int lh=ans(root->left);
        int rh=ans(root->right);
        dia=max(dia,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=INT_MIN;
        if(root==NULL){
            return 0;
        }
        ans(root);
        return dia;
    }
};