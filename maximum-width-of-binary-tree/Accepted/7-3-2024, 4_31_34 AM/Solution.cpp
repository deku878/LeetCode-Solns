// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        std::queue<std::pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});
        unsigned long long maxWidth = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            unsigned long long currMin = q.front().first;
            unsigned long long currMax = q.back().first;
            maxWidth = std::max(maxWidth, currMax - currMin + 1);
            
            for (int i = 0; i < sz; i++) {
                auto x = q.front();
                q.pop();
                unsigned long long index = x.first - currMin;
                TreeNode* node = x.second;
                
                if (node->left != nullptr) {
                    q.push({2 * index + 1, node->left});
                }
                if (node->right != nullptr) {
                    q.push({2 * index + 2, node->right});
                }
            }
        }
        
        return maxWidth;
    }
};