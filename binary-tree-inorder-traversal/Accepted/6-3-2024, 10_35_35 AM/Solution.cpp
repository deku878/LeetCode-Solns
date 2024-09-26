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
        vector<int>result;
        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }
            else{
                auto leftchild=curr->left;
                while(leftchild->right!=NULL){
                    leftchild=leftchild->right;
                }
                leftchild->right=curr;
                auto temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return result;
    }
};