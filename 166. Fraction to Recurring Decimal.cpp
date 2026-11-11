class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0)) result += '-';

        // long long avoids overflow for INT_MIN
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result;

        result += '.';

        // A repeated remainder means the digits start repeating from where we first saw it
        unordered_map<long long, int> seenAt;  // remainder -> index in result
        while (rem != 0) {
            if (seenAt.count(rem)) {
                result.insert(seenAt[rem], "(");
                result += ')';
                break;
            }
            seenAt[rem] = result.size();
            rem *= 10;
            result += char('0' + rem / den);
            rem %= den;
        }
        return result;
    }
};
