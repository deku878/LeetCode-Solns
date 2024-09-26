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
    bool checker(TreeNode* root,int &maxi,int mini){
        if(root==NULL){
            return true;
        }
        if(root->val>=maxi or root->val<=mini){
            return false;
        }
        return checker(root->left,root->val,mini) and checker(root->right,maxi,root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int maxi=INT_MAX;
        int mini=INT_MIN;
        return checker(root,maxi,mini);
    }
};