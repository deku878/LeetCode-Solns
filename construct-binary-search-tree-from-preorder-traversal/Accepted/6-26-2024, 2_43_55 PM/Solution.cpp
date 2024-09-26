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
    TreeNode* build(vector<int>&a,int &i,int &x1){
       if(i==a.size() or a[i]>=x1){
        return NULL;
       }
       TreeNode* x=new TreeNode(a[i++]);
       x->left=build(a,i,x->val);
       x->right=build(a,i,x1);
       return x;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int maxm=INT_MAX;
        return build(preorder,i,maxm);
    }
};