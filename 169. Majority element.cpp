class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int target = nums.size() / 2;
        
        for (int num : nums) {
            counts[num]++; // Increment the frequency of the number
            
            // Check if this number has crossed the majority threshold
            if (counts[num] > target) {
                return num;
            }
        }
        
        return -1; // Fallback, though the problem guarantees an answer
    }
};

