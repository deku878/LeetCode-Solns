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
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        q.push({0,root});
        map<int,vector<int>>mp;
        mp[0].push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            map<int,vector<int>>mp1;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                if(x.second->left!=NULL){
                    mp1[x.first-1].push_back(x.second->left->val);
                    q.push({x.first-1,x.second->left});
                }
                if(x.second->right!=NULL){
                    mp1[x.first+1].push_back(x.second->right->val);
                    q.push({x.first+1,x.second->right});
                }}
                for(auto m:mp1){
                    vector<int>p=m.second;
                    sort(p.begin(),p.end());
                    for(int i=0;i<p.size();i++){
                        mp[m.first].push_back(p[i]);
                    }
                }
            }
       
        for(auto m:mp){
            vector<int>x=m.second;
            res.push_back(x);
        }
        return res;
    }
};