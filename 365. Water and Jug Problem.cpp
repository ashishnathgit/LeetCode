// Difficulty: Medium | Time: O(log(min(x, y))) | Space: O(1) | Pattern: Math | Use: Reachability of target linear combinations via Bezout's identity
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target == 0) return true;
        if (x + y < target) return false;
        return target % gcd(x, y) == 0;
    }

private:
    int gcd(int a, int b) const {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
};
