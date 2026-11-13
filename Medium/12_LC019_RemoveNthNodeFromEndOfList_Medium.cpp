// LeetCode 19 - Remove Nth Node From End of List
// Question: Remove the nth node from the end of a linked list and return
// the head of the modified list.
// Approach: Two pointers separated by n nodes, with a dummy node.
// Time: O(n) | Space: O(1)
// Note: LeetCode provides the ListNode definition.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
};
