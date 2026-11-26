#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 94. Binary Tree Inorder Traversal */

class Solution {
    vector< int > vals;
    void traverse(TreeNode* curr) {
        if (curr == nullptr) return;
        if (curr->left != nullptr) traverse(curr->left);
        vals.push_back(curr->val);
        if (curr->right != nullptr) traverse(curr->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return vals;
    }
};
