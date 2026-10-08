#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 23. Merge k Sorted Lists */

struct Compare {
    bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) {
        return a.first > b.first; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq;
        for (auto node: lists) if (node != nullptr) pq.push({node->val, node});
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            curr->next = new ListNode(top.first);
            curr = curr->next;
            top.second = top.second->next;
            if (top.second != nullptr) pq.push({top.second->val, top.second});
        }
        return head->next;
    }
};
