class Solution {
public:
    int climbStairs(int n) {
        // Ways to reach step i = ways(i-1) + ways(i-2), like Fibonacci
        if (n <= 2) {
            return n;
        }

        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
