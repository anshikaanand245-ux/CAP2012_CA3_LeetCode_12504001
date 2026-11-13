// LeetCode 25 - Reverse Nodes in k-Group
// Question: Reverse linked-list nodes k at a time. If fewer than k nodes
// remain at the end, leave those nodes in their original order.
// Approach: Check that a full group exists, reverse its links, then continue.
// Time: O(n) | Space: O(1)
// Note: LeetCode provides the ListNode definition.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrevious = &dummy;

        while (true) {
            ListNode* kth = groupPrevious;
            for (int i = 0; i < k && kth != nullptr; ++i) {
                kth = kth->next;
            }
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            while (current != groupNext) {
                ListNode* nextNode = current->next;
                current->next = previous;
                previous = current;
                current = nextNode;
            }

            ListNode* oldGroupFirst = groupPrevious->next;
            groupPrevious->next = kth;
            groupPrevious = oldGroupFirst;
        }
        return dummy.next;
    }
};
