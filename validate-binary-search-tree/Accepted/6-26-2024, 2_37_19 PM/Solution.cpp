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
    bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
        if(root==NULL){
            return true;
        }
        if(root->val>=maxVal or root->val<=minVal){
            return false;
        }
        return isValidBSTHelper(root->left,minVal,root->val) and isValidBSTHelper(root->right,root->val,maxVal);
    }

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
};