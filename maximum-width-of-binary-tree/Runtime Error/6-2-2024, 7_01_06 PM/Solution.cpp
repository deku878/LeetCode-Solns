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
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int last,first;
        int maxi=INT_MIN;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto kl=q.front();
                q.pop();
                if(i==0){
                    first=kl.second;
                }
                if(i==k-1){
                    last=kl.second;
                }
                if(kl.first->left){
                    q.push({kl.first->left,kl.second*2+1});
                }
                if(kl.first->right){
                    q.push({kl.first->right,kl.second*2+2});
                }
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};