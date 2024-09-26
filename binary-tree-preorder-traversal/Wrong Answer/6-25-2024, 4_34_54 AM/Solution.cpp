// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preo;
        if(root==NULL){
            return preo;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            auto roo=st.top();
            st.pop();
            preo.push_back(roo->val);
            if(roo->left!=NULL){
                st.push(roo->left);
            }
            if(roo->right!=NULL){
                st.push(roo->right);
            }
        }
        return preo;
    }
};