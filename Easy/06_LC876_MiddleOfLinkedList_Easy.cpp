// LeetCode 876 - Middle of the Linked List
// Question: Return the middle node of a singly linked list. If there are
// two middle nodes, return the second one.
// Approach: Slow pointer moves one node; fast pointer moves two.
// Time: O(n) | Space: O(1)
// Note: LeetCode provides the ListNode definition.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
