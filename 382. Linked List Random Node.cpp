// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Linked List | Use: Reservoir sampling for uniform selection over unknown-length streams
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
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int chosen = 0;
        int i = 1;
        for (ListNode* cur = head; cur; cur = cur->next, ++i) {
            if (rand() % i == 0) chosen = cur->val;
        }
        return chosen;
    }

private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
