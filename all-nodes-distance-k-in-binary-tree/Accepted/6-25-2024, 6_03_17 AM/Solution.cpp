// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void creategraph(vector<vector<int>>&adj,TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            creategraph(adj,root->left);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            creategraph(adj,root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>>adj(501);
        creategraph(adj,root);
        queue<pair<int,int>>q;
        q.push({target->val,0});
        vector<bool>vis(501,0);
        vis[target->val]=1;
        vector<int>yt;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x.second==k){
                yt.push_back(x.first);
            }
            for(auto y:adj[x.first]){
                if(!vis[y]){
                    q.push({y,x.second+1});
                    vis[y]=true;
                }
            }
        }
        return yt;
    }
};