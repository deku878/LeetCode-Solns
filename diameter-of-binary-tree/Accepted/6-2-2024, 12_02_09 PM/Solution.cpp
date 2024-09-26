// https://leetcode.com/problems/diameter-of-binary-tree

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
    int help(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;                         // Base case: NULL node has height 0
        int left = help(root->left, diameter);             // Height of left subtree
        int right = help(root->right, diameter);          // Height of right subtree
        diameter = max(diameter, left + right);          // Update diameter
        return max(left, right) + 1;                    // Return current subtree height
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;                            // Initialize diameter to 0
        help(root, diameter);                       // Call helper function
        return diameter;                           // Return final diameter
    }
};