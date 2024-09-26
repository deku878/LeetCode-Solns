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
       vector<vector<int>> result;
       vector<int> temp;
       if(root == nullptr)
            return result;

       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode* x=q.front();
            temp.push_back(x->val);
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
            q.pop();
        }
        result.push_back(temp);
        temp.clear();
       }
       return result;
    }
};