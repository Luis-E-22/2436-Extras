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
           ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move first to the end, second follows
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the target node
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

