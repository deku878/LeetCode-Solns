// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long int,TreeNode*>>q;
        q.push({0,root});
        long long int minwidth=1;
        while(!q.empty()){
            int sz=q.size();
            long long int currmin=INT_MAX;
            long long int currmax=INT_MIN;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                currmin=min(x.first,currmin);
                currmax=max(x.first,currmax);
                if(x.second->left!=NULL){
                    long long int res=2*x.first+1;
                    q.push({res,x.second->left});
                }
                if(x.second->right!=NULL){
                     long long int res=2*x.first+2;
                     q.push({res,x.second->right});
                }
            }
            minwidth=max(currmax-currmin+1,minwidth);
        }
        return minwidth;
    }
};