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

        int sum=u->val+lftr+rightr;
        maxs=max(maxs,sum);

        int maxu=u->val+max(lftr,rightr);
        return maxu;
    }
    int maxPathSum(TreeNode* root) {
        int maxde=0;
        maxi(root,maxde);
        return maxde;
    }
};