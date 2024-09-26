// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        while(!q.empty()){
            vector<int>x;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto k=q.front();
                q.pop();
                x.push_back(k->val);
                if(k->left!=NULL){
                    q.push(k->left);
                }
                if(k->right!=NULL){
                    q.push(k->right);
                }
            }
            res.push_back(x);
        }
        return res;
    }
};