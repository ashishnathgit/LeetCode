**
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current) {
            ListNode* next = current->next;  // Save next before we break the link
            current->next = prev;             // Flip the pointer backward
            prev = current;                   // Move prev forward
            current = next;                   // Move current forward
        }
        
        return prev;  // prev is now pointing at the old last node (new head)
    }
};
