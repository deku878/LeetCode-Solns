// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small=min(p->val,q->val);
        int maxm=max(p->val,q->val);
        while(root!=NULL){
            if(root->val<small){
                root=root->right;
            }
            else if(root->val>maxm){
                root=root->left;
            }
            else{
                return root;
            }
        }
        return root;
    }
};