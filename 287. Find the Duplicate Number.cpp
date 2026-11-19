// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Cycle detection in linked structures and pointer graphs
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Treat values as next-pointers; the duplicate is the cycle entrance (Floyd)
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Reset one pointer; they meet at the cycle start
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
