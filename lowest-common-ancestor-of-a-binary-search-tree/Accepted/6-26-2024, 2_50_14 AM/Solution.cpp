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
        int large=max(p->val,q->val);
        TreeNode* x=root;
        while(x!=NULL){
            if(x->val<small){
                x=x->right;
            }
            else if(x->val>large){
                x=x->left;
            }
            else{
                return x;
            }
        }
        return NULL;
    }
};