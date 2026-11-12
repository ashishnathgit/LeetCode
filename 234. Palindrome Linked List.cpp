// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Fast & Slow Pointers + Reversal | Use: Symmetric sequence checks on streams
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half.
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        for (ListNode *a = head, *b = prev; b; a = a->next, b = b->next)
            if (a->val != b->val) return false;
        return true;
    }
};
