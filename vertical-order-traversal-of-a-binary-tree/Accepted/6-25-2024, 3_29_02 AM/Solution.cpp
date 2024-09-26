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
             queue<pair<TreeNode*,int>>q;
             q.push({root,0});
             map<int,vector<int>>mp1;
             while(!q.empty()){
                int sz=q.size();
                map<int,vector<int>>mp;
                for(int i=0;i<sz;i++){
                    auto x=q.front();
                    q.pop();
                    if(x.first->left!=NULL){
                        q.push({x.first->left,x.second-1});
                    }
                    if(x.first->right!=NULL){
                        q.push({x.first->right,x.second+1});
                    }
                    mp[x.second].push_back(x.first->val);
                }
                for(auto m:mp){
                    sort(m.second.begin(),m.second.end());
                    for(auto i:m.second){
                        mp1[m.first].push_back(i);
                    }
                }
             }
             vector<vector<int>>lo;
             for(auto m:mp1){
                lo.push_back(m.second);
             }
             return lo;
    }
};