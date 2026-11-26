#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 111. Minimum Depth of Binary Tree */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ldepth = 0, rdepth = 0;
        if (root->left != nullptr) ldepth = minDepth(root->left);
        if (root->right != nullptr) rdepth = minDepth(root->right);
        if (ldepth == 0) return rdepth + 1;
        if (rdepth == 0) return ldepth + 1;
        return 1 + min(ldepth, rdepth);
    }
};
