// Difficulty: Medium | Time: O(n³) | Space: O(n) | Pattern: String | Use: Sequence validation and arbitrary-precision string arithmetic
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int len1 = 1; len1 <= n / 2; ++len1) {
            if (num[0] == '0' && len1 > 1) break;

            for (int len2 = 1; max(len1, len2) <= n - len1 - len2; ++len2) {
                if (num[len1] == '0' && len2 > 1) break;

                string a = num.substr(0, len1);
                string b = num.substr(len1, len2);
                int pos = len1 + len2;

                while (pos < n) {
                    string sum = addStrings(a, b);
                    if (pos + (int)sum.size() > n || num.compare(pos, sum.size(), sum) != 0) {
                        break;
                    }
                    pos += sum.size();
                    a = move(b);
                    b = move(sum);
                }
                if (pos == n) return true;
            }
        }
        return false;
    }

private:
    string addStrings(const string& a, const string& b) {
        string res;
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back('0' + (sum % 10));
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
