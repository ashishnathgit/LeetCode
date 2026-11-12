// Difficulty: Medium | Time: O(1) | Space: O(1) | Pattern: Linked List | Use: In-place removal when only a node handle is available
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node into this one, then unlink the next node.
        ListNode* nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
        delete nxt;
    }
};
