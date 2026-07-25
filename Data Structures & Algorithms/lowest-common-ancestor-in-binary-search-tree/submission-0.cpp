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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return NULL;
        else if (root == p) return p;
        else if (root == q) return q;
        int rootValue = root->val;
        int pValue = p->val;
        int qValue = q->val;
        if ((pValue < rootValue && qValue > rootValue) || (qValue < rootValue && pValue > rootValue)) return root;
        else if (pValue<rootValue && qValue<rootValue) return lowestCommonAncestor(root->left,p,q);
        else if (pValue>rootValue && qValue>rootValue) return lowestCommonAncestor(root->right,p,q);
    }
};
