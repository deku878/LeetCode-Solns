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
    TreeNode* helper(vector<int>& preorder,int& id,int limit){
        if(id==preorder.size() or preorder[id]>limit){
            return NULL;
        }
        int root_val=preorder[id];
        TreeNode* root=new TreeNode(root_val);
        id++;
        root->left=helper(preorder,id,root_val);
        root->right=helper(preorder,id,limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id=0;
        int m=INT_MAX;
        return helper(preorder,id,m);
    }
};