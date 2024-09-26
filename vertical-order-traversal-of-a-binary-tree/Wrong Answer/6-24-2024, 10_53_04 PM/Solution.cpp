// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        map<int,vector<int>>mp;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                if(x.second->left!=NULL){
                    q.push({x.first-1,x.second->left});
                }
                if(x.second->right!=NULL){
                    q.push({x.first+1,x.second->right});
                }
                mp[x.first].push_back(x.second->val);
            }
        }
        vector<vector<int>>x;
        for(auto m:mp){
            sort(m.second.begin(),m.second.end());
            x.push_back(m.second);
        }
        return x;
    }
};