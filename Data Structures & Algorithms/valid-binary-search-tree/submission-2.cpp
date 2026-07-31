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
    bool isValidBST(TreeNode* root) {
        // Use standard 64-bit integer limits to protect against INT_MIN and INT_MAX overflows
        return isValid(LLONG_MIN, LLONG_MAX, root);
    }

private:
    bool isValid(long long low, long long high, TreeNode* root) {
        if (root == nullptr) return true;
        
        // The current node value must strictly live between the low and high boundaries
        if (root->val <= low || root->val >= high) return false;
        
        // Left child must be smaller than current value; Right child must be larger
        return isValid(low, root->val, root->left) && 
               isValid(root->val, high, root->right);
    }
};
