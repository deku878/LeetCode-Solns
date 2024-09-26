// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>>c;
            return c;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>kl;
        vector<int>x;
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            cnt++;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                x.push_back(node->val);
            }
            if(cnt%2==0){
            reverse(x.begin(),x.end());}
            kl.push_back(x);
            x.clear();
        }
        return kl;
    }
};