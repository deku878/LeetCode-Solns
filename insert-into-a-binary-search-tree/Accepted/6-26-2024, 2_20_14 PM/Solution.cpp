// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insert(TreeNode* root,int val1){
       if(root==NULL){
        TreeNode* y=new TreeNode(val1);
        return y;
       }
       else if(val1>root->val){
        root->right=insert(root->right,val1);
       }
       else if(val1<root->val){
        root->left=insert(root->left,val1);
       }
       return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root,val);
    }
};