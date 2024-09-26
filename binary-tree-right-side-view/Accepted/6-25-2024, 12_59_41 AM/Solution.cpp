// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            vector<int>c;
            return c;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>z;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
                if(i==sz-1){
                    z.push_back(x->val);
                }
            }
        }
        return z;
    }
};