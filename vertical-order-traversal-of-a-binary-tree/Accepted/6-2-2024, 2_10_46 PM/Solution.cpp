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
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int r=x.second.first;
            int s=x.second.second;
            TreeNode* lei=x.first;
            mp[r][s].insert(lei->val);
            if(x.first->left){
                q.push({x.first->left,{r-1,s+1}});}
            if(x.first->right){
                q.push({x.first->right,{r+1,s+1}});
            }
        }
        vector<vector<int>>lo;
        for(auto d:mp){
            vector<int>col;
            for(auto x:d.second){
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            lo.push_back(col);
        }
        return lo;
    }
};