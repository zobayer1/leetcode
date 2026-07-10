struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 24. Swap Nodes in Pairs */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = second->next;
        second->next = first;
        head = second;

        ListNode* ptemp = head->next;
        ListNode* temp = head->next->next;

        while (temp != nullptr && temp->next != nullptr) {
            first = temp;
            second = temp->next;
            first->next = second->next;
            second->next = first;
            ptemp->next = second;
            ptemp = second->next;
            temp = second->next->next;
        }
        return head;
    }
};
