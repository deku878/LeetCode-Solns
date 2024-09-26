// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* build(vector<int>&p,vector<int>&in,int ps,int pe,int is,int ie,map<int,int>&mp){
        if(is>ie or ps>pe){
            return NULL;
        }
        int idx=mp[p[ps]];
        int numsleft=mp[p[ps]]-is;
        TreeNode* x=new TreeNode(p[ps]);
        x->left=build(p,in,ps+1,ps+numsleft,is,idx-1,mp);
        x->right=build(p,in,ps+numsleft+1,pe,idx+1,ie,mp);
        return x;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()){
            return NULL;
        }
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,mp);
    }
};