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
        if (root==NULL) return true;
        return isValid(-1001,root->val,root->left) && isValid(root->val,1001,root->right);
    }
    bool isValid(int low, int high,TreeNode* root){
        if (root==NULL) return true;
        if (root->val <= low || root->val >= high) return false;
        return isValid(low,root->val,root->left) && isValid(root->val,high,root->right);
    }
};
