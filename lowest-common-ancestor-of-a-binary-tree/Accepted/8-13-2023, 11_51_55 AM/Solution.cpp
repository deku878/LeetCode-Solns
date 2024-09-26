// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val){
            return p;
        }
        else if(root->val==q->val){
            return q;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        if(leftans==NULL and rightans==NULL){
            return NULL;
        }
        else if(rightans!=NULL and leftans==NULL){
            return rightans;
        }
        else if(leftans!=NULL and rightans==NULL){
            return leftans;
        }
        else{
            return root;
        }
    }
};