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
        TreeNode* temp=root;
        TreeNode* t1=root->left;
        TreeNode* t2=root->right;
        while(t1!=NULL){
            vector<int>c;
            c.push_back(t1->val);
            x.push_back(c);
            t1=t1->left;
        }
        reverse(x.begin(),x.end());
        vector<int>x1=mp[0];
        sort(x1.begin(),x1.end());
        x.push_back(x1);
        while(t2!=NULL){
            vector<int>d;
            d.push_back(t2->val);
            x.push_back(d);
            t2=t2->right;
        }
        return x;
    }
};