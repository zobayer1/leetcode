#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 25. Reverse Nodes in k-Group */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode *curr = head;
        while (curr != nullptr) {
            s.push(curr);
            ListNode *nextptr = curr->next;
            if (s.size() == k) {
                while (!s.empty()) {
                    ListNode *top = s.top(); s.pop();
                    prev->next = top;
                    prev = prev->next;
                }
                prev->next = nextptr;
            }
            curr = nextptr;
        }
        return dummy->next;
    }
};
