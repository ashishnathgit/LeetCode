// Difficulty: Medium | Time: O(n²) | Space: O(1) | Pattern: Linked List | Use: Keeping small, nearly sorted lists in order as items arrive
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);  // Head of the sorted list
        ListNode* cur = head;

        while (cur) {
            ListNode* next = cur->next;

            // Find the node after which cur belongs in the sorted list
            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }

            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        return dummy.next;
    }
};
