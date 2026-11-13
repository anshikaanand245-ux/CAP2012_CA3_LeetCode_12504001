// LeetCode 24 - Swap Nodes in Pairs
// Question: Swap every two adjacent nodes in a linked list and return its head.
// Approach: Rewire links in pairs using a dummy node.
// Time: O(n) | Space: O(1)
// Note: LeetCode provides the ListNode definition.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* previous = &dummy;

        while (previous->next != nullptr &&
               previous->next->next != nullptr) {
            ListNode* first = previous->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            previous->next = second;

            previous = first;
        }
        return dummy.next;
    }
};
