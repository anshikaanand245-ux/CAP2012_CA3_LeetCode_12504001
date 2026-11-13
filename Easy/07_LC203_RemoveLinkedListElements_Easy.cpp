// LeetCode 203 - Remove Linked List Elements
// Question: Remove every node whose value equals val and return the new head.
// Approach: Use a dummy node so that removing the original head is easy.
// Time: O(n) | Space: O(1)
// Note: LeetCode provides the ListNode definition.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return dummy.next;
    }
};
