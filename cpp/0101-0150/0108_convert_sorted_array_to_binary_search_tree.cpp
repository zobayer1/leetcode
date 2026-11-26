#include <stack>
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

/* 108. Convert Sorted Array to Binary Search Tree */

struct Range {
    int i, j;
    TreeNode* node;
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = new TreeNode();
        if (nums.size() == 1) {
            root->val = nums[0];
            return root;
        }
        stack<Range> S;
        S.push({0, (int)nums.size()-1, root});
        while (!S.empty()) {
            auto top = S.top(); S.pop();
            int mid = (top.i + top.j) / 2;
            top.node->val = nums[mid];
            if (top.i < mid) {
                top.node->left = new TreeNode();
                S.push({top.i, mid-1, top.node->left});
            }
            if (top.j > mid) {
                top.node->right = new TreeNode();
                S.push({mid+1, top.j, top.node->right});
            }
        }
        return root;
    }
};
