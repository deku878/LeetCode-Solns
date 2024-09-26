// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxi(TreeNode* u,int& maxs){
        if(u==NULL){
            return 0;
        }
        int lftr=maxi(u->left,maxs);
        int rightr=maxi(u->right,maxs);

        int sum=max({u->val+lftr+rightr,u->val+lftr,u->val+rightr,u->val});
        maxs=max(maxs,sum);

        int maxu=max(u->val+max(lftr,rightr),u->val);
        return maxu;
    }
    int maxPathSum(TreeNode* root) {
        int maxde=INT_MIN;
        maxi(root,maxde);
        return maxde;
    }
};