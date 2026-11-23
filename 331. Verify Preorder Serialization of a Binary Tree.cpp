// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Tree | Use: Streaming syntax validation of serialized tree structures
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            if (slots == 0) return false;

            int j = i;
            while (j < n && preorder[j] != ',') ++j;
            if (j - i == 1 && preorder[i] == '#') {
                --slots;
            } else {
                ++slots;  // Consumes 1 slot and opens 2 child slots
            }
            i = j;
        }
        return slots == 0;
    }
};
