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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        int a, b, s, c = 0;
        ListNode *head = new ListNode();
        ListNode *curr = head;
        while (ptr1 != nullptr || ptr2 != nullptr || c > 0) {
            a = (ptr1 == nullptr)? 0 : ptr1->val;
            b = (ptr2 == nullptr)? 0 : ptr2->val;
            s = (a + b + c) % 10;
            c = (a + b + c) / 10;
            curr->next = new ListNode(s);
            curr = curr->next;
            ptr1 = (ptr1 != nullptr)? ptr1->next : nullptr;
            ptr2 = (ptr2 != nullptr)? ptr2->next : nullptr;
        }
        return head->next;
    }
};
