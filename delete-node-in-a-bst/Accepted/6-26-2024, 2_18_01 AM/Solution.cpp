// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deletex(TreeNode* root,int key){
        if (root == NULL) {
        return NULL;
    }

    if (key < root->val) {
        root->left = deletex(root->left, key);
    } else if (key > root->val) {
        root->right = deletex(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder predecessor (rightmost in the left subtree)
        TreeNode* temp = root->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }

        // Copy the inorder predecessor's content to this node
        root->val = temp->val;

        // Delete the inorder predecessor
        root->left = deletex(root->left, temp->val);
    }
    return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletex(root,key);
    }
};