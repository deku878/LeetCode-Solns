// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* solve(TreeNode* node,int val){
        if(node==NULL){
            node=new TreeNode(val);
            return node;
        }
        if(val<node->val){
            node->left=solve(node->left,val);
        }
        else if(val>node->val){
            node->right=solve(node->right,val);
        }
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};