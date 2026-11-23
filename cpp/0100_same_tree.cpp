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

/* 100. Same Tree */

class Solution {
    void preOrder(TreeNode *curr, vector< int >& nodes) {
        if (curr == nullptr) {
            nodes.push_back(-1000000);
            return;
        }
        nodes.push_back(curr->val);
        preOrder(curr->left, nodes);
        preOrder(curr->right, nodes);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector< int > pNodes, qNodes;
        preOrder(p, pNodes);
        preOrder(q, qNodes);
        return pNodes == qNodes;
    }
};