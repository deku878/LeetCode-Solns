// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deletex(TreeNode* root,int key){
        if(root==NULL){
            return NULL;
        }
        if(key>root->val){
            root->right=deletex(root->right,key);
        }
        else if(key<root->val){
            root->left=deletex(root->left,key);
        }
        else{
            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                TreeNode* temp=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right=deletex(root->right,temp->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletex(root,key);
    }
};