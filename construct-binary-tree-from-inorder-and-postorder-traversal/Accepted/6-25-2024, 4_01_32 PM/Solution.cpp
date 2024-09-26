// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTreep(vector<int>&preorder,int p,int q,vector<int>&inorder,int x,int y,map<int,int>&mp){
        if(p>q or x>y){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[q]);
        int numl=mp[preorder[q]]-x;
        int inr=mp[preorder[q]];
        
        root->left=buildTreep(preorder,p,p+numl-1,inorder,x,inr-1,mp);
        root->right=buildTreep(preorder,p+numl,q-1,inorder,inr+1,y,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTreep(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};