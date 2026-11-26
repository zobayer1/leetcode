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

/* 101. Symmetric Tree */

class Solution {
    void pre_order_normal(TreeNode *root, vector< int >& vals) {
        if (root == nullptr) {
            vals.push_back(-1);
            return;
        }
        vals.push_back(root->val);
        pre_order_normal(root->left, vals);
        pre_order_normal(root->right, vals);
    }

    void pre_order_mirror(TreeNode *root, vector< int >& vals) {
        if (root == nullptr) {
            vals.push_back(-1);
            return;
        }
        vals.push_back(root->val);
        pre_order_mirror(root->right, vals);
        pre_order_mirror(root->left, vals);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector< int > lvals, rvals;
        pre_order_normal(root, lvals);
        pre_order_mirror(root, rvals);
        return lvals == rvals;
    }
};
