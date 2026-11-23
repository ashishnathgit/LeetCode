// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Math | Use: Modular exponentiation with arbitrarily large decimal exponents
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        a %= MOD;
        for (int digit : b) {
            res = (powMod(res, 10) * powMod(a, digit)) % MOD;
        }
        return res;
    }

private:
    static constexpr int MOD = 1337;

    int powMod(int base, int exp) const {
        int res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
};
