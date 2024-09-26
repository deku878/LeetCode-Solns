// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node=root;
        vector<int>inorder;
        while(node!=NULL){
            if(node->left==NULL){
                inorder.push_back(node->val);
                node=node->right;
            }
            else{
                auto real=node->left;
                while(real->right!=NULL and real->right!=node){
                    real=real->right;
                }
                if(real->right==NULL){
                    real->right=node;
                    node=node->left;
                }
                else{
                    real->right=NULL;
                    inorder.push_back(node->val);
                    node=node->right;  
                }
            }
        }
        return inorder;
    }
};