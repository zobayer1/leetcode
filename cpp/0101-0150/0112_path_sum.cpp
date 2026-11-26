struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 112. Path Sum */

class Solution {
    bool traverse(TreeNode * root, int targetSum) {
        if (root == nullptr) return targetSum == 0;
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) return targetSum == 0;
        return (root->left != nullptr && traverse(root->left, targetSum)) || (root->right != nullptr && traverse(root->right, targetSum));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traverse(root, targetSum);
    }
};
