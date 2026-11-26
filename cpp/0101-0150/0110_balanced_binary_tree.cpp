#include <algorithm>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 110. Balanced Binary Tree */

class Solution {
    pair< int, bool > depth(TreeNode* curr) {
        if (curr == nullptr) return {0, true};
        auto l_depth = depth(curr->left);
        if (!l_depth.second) return {0, false};
        auto r_depth = depth(curr->right);
        if (!r_depth.second) return {0, false};
        return {1 + max(l_depth.first, r_depth.first), abs(l_depth.first - r_depth.first) <= 1};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto traversal = depth(root);
        return traversal.second;
    }
};
