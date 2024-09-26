// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool checker=true;
        vector<int>jedi;
        int level=0;
        while(!q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                auto k=q.front();
                q.pop();
                if(k->left){
                    q.push(k->left);
                }
                if(k->right){
                    q.push(k->right);
                }
                jedi.push_back(k->val);
            }
            vector<int>sith;
            sith=jedi;
            reverse(jedi.begin(),jedi.end());
            if(sith!=jedi or jedi.size()!=(1<<level)){
                checker=false;
                break;
            }
            jedi.clear();
            level++;
        }
        return checker;
    }
};