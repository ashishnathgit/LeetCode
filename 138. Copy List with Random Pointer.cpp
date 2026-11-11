// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Linked List | Use: Deep-copying structures that hold cross-references
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Put each copy right after its original: A -> A' -> B -> B' ...
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }

        // Step 2: A copy's random is the node right after the original's random
        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) cur->next->random = cur->random->next;
        }

        // Step 3: Split the woven list back into the original and the copy
        Node* copyHead = head->next;
        for (Node* cur = head; cur; cur = cur->next) {
            Node* copy = cur->next;
            cur->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
        }
        return copyHead;
    }
};
