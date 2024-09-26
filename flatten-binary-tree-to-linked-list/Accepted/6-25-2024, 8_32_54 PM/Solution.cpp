// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        TreeNode* curr=root;
        stack<TreeNode*>st;
        st.push(curr);
        while(!st.empty()){
            auto curr=st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
            curr->right=st.top();}
            curr->left=NULL;
        }
    }
};