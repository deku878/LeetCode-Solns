// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
int maxm=INT_MIN;
public:

    int maxs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = max(0, maxs(root->left));  // Calculate max path sum for left subtree
        int right = max(0, maxs(root->right));  // Calculate max path sum for right subtree

        // Update the maximum path sum using the current node
        maxm = max(maxm, root->val + left + right);

        // Return the maximum path sum for paths passing through the current node
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        maxs(root);
        return maxm;
    }

};