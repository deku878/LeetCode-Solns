// https://leetcode.com/problems/recover-binary-search-tree

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
TreeNode* first = NULL;
TreeNode* prev = NULL;
TreeNode* middle = NULL;
TreeNode* last = NULL;

public:
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);

        if(prev!=NULL and prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=prev=middle=last=NULL;
        inorder(root);
        if(first!=NULL and last!=NULL){
            swap(first->val,last->val);
        }
        else{
            swap(first->val,middle->val);
        }
    }
};