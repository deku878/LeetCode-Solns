// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
           vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != NULL || !st.empty()) {
        // Reach the leftmost node of the current subtree
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        // Process the node
        current = st.top();
        st.pop();
        result.push_back(current->val);

        // Move to the right child
        current = current->right;
    }

    return result;
    }
};