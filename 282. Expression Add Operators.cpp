// Difficulty: Hard | Time: O(4^n) | Space: O(n) | Pattern: Backtracking | Use: Generating candidate formulas in puzzle solvers and calculators
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        string path;
        backtrack(num, target, 0, 0, 0, path, results);
        return results;
    }

private:
    void backtrack(const string& num, int target, int pos, long value, long last,
                   string& path, vector<string>& results) {
        if (pos == (int)num.size()) {
            if (value == target) results.push_back(path);
            return;
        }

        int pathLen = path.size();
        long operand = 0;
        for (int i = pos; i < (int)num.size(); ++i) {
            // Numbers with leading zeros are not allowed
            if (i > pos && num[pos] == '0') break;
            operand = operand * 10 + (num[i] - '0');
            string digits = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                path += digits;
                backtrack(num, target, i + 1, operand, operand, path, results);
                path.resize(pathLen);
                continue;
            }

            path += "+" + digits;
            backtrack(num, target, i + 1, value + operand, operand, path, results);
            path.resize(pathLen);

            path += "-" + digits;
            backtrack(num, target, i + 1, value - operand, -operand, path, results);
            path.resize(pathLen);

            // Multiplication: undo the last operand and apply it multiplied
            path += "*" + digits;
            backtrack(num, target, i + 1, value - last + last * operand, last * operand, path, results);
            path.resize(pathLen);
        }
    }
};
