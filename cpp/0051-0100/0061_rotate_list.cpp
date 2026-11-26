/* 61. Rotate List */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* last = head;
        int total = 0;
        while (last != nullptr) {
            total++;
            if (last->next == nullptr) break;
            last = last->next;
        }
        if (!total) return head;
        k = total - k%total;
        if (k == total) return head;
        last->next = head;
        ListNode* curr = head;
        for (int i = 0; i < k-1; i++) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};
