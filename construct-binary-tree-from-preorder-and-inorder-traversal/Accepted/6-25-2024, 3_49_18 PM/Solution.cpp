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
    TreeNode* buildTreep(vector<int>&pre,int x,int y,vector<int>&in,int p,int q,map<int,int>&m){
        if(x>y or p>q){
            return NULL;
        }
        TreeNode* st=new TreeNode(pre[x]);
        int numsleft=m[pre[x]]-p;
        int inr=m[pre[x]];
        st->left=buildTreep(pre,x+1,x+numsleft,in,p,inr-1,m);
        st->right=buildTreep(pre,x+numsleft+1,y,in,inr+1,q,m);
        return st;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()){
            return NULL;
        }
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root1=buildTreep(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root1;
    }
};