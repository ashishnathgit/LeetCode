// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Pair matching on sorted data (budget pairing)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = (int)numbers.size() - 1;

        // The array is sorted, so move the pointer that brings the sum closer to target
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};  // 1-indexed
            if (sum < target) left++;
            else right--;
        }
        return {};
    }
};
