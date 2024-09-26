// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* build(int &i,vector<int>&a,int maxm){
        if(i==a.size() or a[i]>maxm){
            return NULL;
        }
        TreeNode* node=new TreeNode(a[i++]);
        node->left=build(i,a,node->val);
        node->right=build(i,a,maxm);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(i,preorder,INT_MAX);
    }
};