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
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lefth=height(root->left);
    int righth=height(root->right);
    int ans=1+max(lefth,righth);
    return ans;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;}
        int lefth=height(root->left);
        int righth=height(root->right);
        int diff=abs(lefth-righth);
        bool ans=(diff<=1);
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);
        if(ans and leftans and rightans){
            return true;
        }
        else{
            return false;
        }}
};