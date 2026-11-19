// Difficulty: Medium | Time: O(Catalan(n)) | Space: O(Catalan(n)) | Pattern: Divide and Conquer | Use: Enumerating evaluation orders in expression parsers
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return solve(expression, memo);
    }

private:
    vector<int> solve(const string& expr, unordered_map<string, vector<int>>& memo) {
        if (auto it = memo.find(expr); it != memo.end()) return it->second;

        vector<int> results;
        for (int i = 0; i < (int)expr.size(); ++i) {
            char op = expr[i];
            if (op != '+' && op != '-' && op != '*') continue;

            // Split at every operator and combine all left/right results
            vector<int> left = solve(expr.substr(0, i), memo);
            vector<int> right = solve(expr.substr(i + 1), memo);
            for (int a : left)
                for (int b : right)
                    results.push_back(op == '+' ? a + b : op == '-' ? a - b : a * b);
        }

        // No operator: the expression is a single number
        if (results.empty()) results.push_back(stoi(expr));
        return memo[expr] = results;
    }
};
