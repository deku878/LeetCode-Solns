// https://leetcode.com/problems/balanced-binary-tree

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
    int maxd(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        int lh=maxd(root->left);
        int rh=maxd(root->right);
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=maxd(root->left);
        int rh=maxd(root->right);
        if(abs(lh-rh)>1){
            return false;
        }
        return isBalanced(root->left) and isBalanced(root->right);
    }
};