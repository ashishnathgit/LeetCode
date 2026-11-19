// Difficulty: Hard | Time: O(log n) | Space: O(1) | Pattern: String | Use: Writing amounts in words on cheques and invoices
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        const vector<pair<int, string>> scales = {
            {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {1, ""}};

        string result;
        for (const auto& [value, name] : scales) {
            int chunk = num / value;
            num %= value;
            if (chunk == 0) continue;

            // Each chunk is < 1000; convert it and append its scale word
            string words = belowThousand(chunk);
            if (!name.empty()) words += " " + name;
            result += (result.empty() ? "" : " ") + words;
        }
        return result;
    }

private:
    const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};

    string belowThousand(int n) {
        string out;
        if (n >= 100) {
            out = ones[n / 100] + " Hundred";
            n %= 100;
        }
        if (n >= 20) {
            out += (out.empty() ? "" : " ") + tens[n / 10];
            n %= 10;
        }
        if (n > 0) out += (out.empty() ? "" : " ") + ones[n];
        return out;
    }
};
