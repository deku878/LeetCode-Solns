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
        // left root right

        while(node!=NULL){
            if(node->left==NULL){
                inorder.push_back(node->val);
                node=node->right;
            }
            else{
                auto temp=node->left;
                while(temp->right!=NULL and temp->right!=node){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=node;
                    node=node->left;
                }
                else{
                    temp->right=NULL;
                    inorder.push_back(node->val);
                    node=node->right;
                }
            }
        }
        return inorder;
    }
};