// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
                if (!root) return {};

        // Queue for BFS and a map to store nodes by their horizontal distance
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, vector<int>> nodes; // horizontal distance -> nodes at that distance

        while (!q.empty()) {
            int size = q.size();
            map<int, vector<int>> levelNodes; // temporary map for nodes at the same horizontal distance
            
            for (int i = 0; i < size; ++i) {
                auto [node, hd] = q.front();
                q.pop();
                
                // Add node value to the temporary map at current horizontal distance
                levelNodes[hd].push_back(node->val);
                
                // Enqueue left child with adjusted horizontal distance
                if (node->left) {
                    q.push({node->left, hd - 1});
                }
                
                // Enqueue right child with adjusted horizontal distance
                if (node->right) {
                    q.push({node->right, hd + 1});
                }
            }
            
            // Merge temporary map into the main map, sorting values within each horizontal distance
            for (auto& levelPair : levelNodes) {
                auto& vals = levelPair.second;
                sort(vals.begin(), vals.end()); // sort values at the same horizontal distance
                nodes[levelPair.first].insert(nodes[levelPair.first].end(), vals.begin(), vals.end());
            }
        }
        
        // Prepare result from the nodes map
        vector<vector<int>> result;
        for (auto& pair : nodes) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};