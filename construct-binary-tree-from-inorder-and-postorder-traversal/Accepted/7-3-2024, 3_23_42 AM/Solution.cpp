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
    TreeNode* build(vector<int>&i,vector<int>&po,int is,int ie,int ps,int pe,map<int,int>&mp){
        if(is>ie or ps>pe){
            return NULL;
        }
        TreeNode* n=new TreeNode(po[pe]);
        int numsleft=mp[po[pe]]-is;
        int idx=mp[po[pe]];
       
        n->left=build(i,po,is,idx-1,ps,ps+numsleft-1,mp);
        n->right=build(i,po,idx+1,ie,ps+numsleft,pe-1,mp);
        return n;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }
};