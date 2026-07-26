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
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return root;
        invertTreeRecursion(root->left, root->right);
        return root;
    }
    void invertTreeRecursion(TreeNode* left,TreeNode* right){
        if (left == nullptr || right == nullptr) return;
        swap(left->val,right->val);
        invertTreeRecursion(left->left,right->right);
        invertTreeRecursion(left->right,right->left);
    }
};
