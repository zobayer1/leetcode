/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr_r = head, *ptr_l = nullptr;
        for (int i = 0; ptr_r; ++i) {
            ptr_r = ptr_r->next;
            if (i == n) ptr_l = head;
            else if (i > n) ptr_l = ptr_l->next;
        }
        if (ptr_l == nullptr) {
            ptr_l = head;
            head = head->next;
            delete ptr_l;
        } else {
            ListNode *tmp = ptr_l->next;
            if (ptr_l->next) ptr_l->next = ptr_l->next->next;
            delete tmp;
        }
        return head;
    }
};
