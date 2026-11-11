class Solution {
public:
    bool isHappy(int n) {
        // The sequence either reaches 1 or loops; detect the loop with slow/fast pointers
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }

private:
    // Sum of the squares of the digits
    int next(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
