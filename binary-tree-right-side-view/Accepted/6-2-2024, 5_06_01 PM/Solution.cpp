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
        if(root==NULL){
            vector<int>u;
            return u;
        }
        queue<TreeNode*>q;
        vector<int>x,y;
        q.push(root);
        while(!q.empty()){
            int lo=q.size();
            for(int i=0;i<lo;i++){
            auto j=q.front();
            q.pop();
            if(j->left){
                q.push(j->left);
            }
            if(j->right){
                q.push(j->right);
            }
            x.push_back(j->val);
            }
            y.push_back(x.back());
            x.clear();
    }
    return y;
    }
};