// Difficulty: Hard | Time: O(2^n) | Space: O(n) | Pattern: Backtracking | Use: Syntax error recovery and minimal expression repair
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remLeft = 0, remRight = 0;
        for (char c : s) {
            if (c == '(') {
                ++remLeft;
            } else if (c == ')') {
                if (remLeft > 0) --remLeft;
                else ++remRight;
            }
        }

        unordered_set<string> results;
        string path;
        dfs(s, 0, 0, remLeft, remRight, false, path, results);
        return vector<string>(results.begin(), results.end());
    }

private:
    void dfs(const string& s, int i, int open, int remLeft, int remRight,
             bool prevRemoved, string& path, unordered_set<string>& results) {
        if (open < 0 || remLeft < 0 || remRight < 0 || (int)s.size() - i < remLeft + remRight) {
            return;
        }
        if (i == (int)s.size()) {
            if (open == 0 && remLeft == 0 && remRight == 0) {
                results.insert(path);
            }
            return;
        }

        char c = s[i];
        if (c == '(' || c == ')') {
            // Only remove the first of a run of identical parentheses unless the prior was removed
            if (!(i > 0 && s[i] == s[i - 1] && !prevRemoved)) {
                if (c == '(' && remLeft > 0) {
                    dfs(s, i + 1, open, remLeft - 1, remRight, true, path, results);
                } else if (c == ')' && remRight > 0) {
                    dfs(s, i + 1, open, remLeft, remRight - 1, true, path, results);
                }
            }

            path.push_back(c);
            dfs(s, i + 1, open + (c == '(' ? 1 : -1), remLeft, remRight, false, path, results);
            path.pop_back();
        } else {
            path.push_back(c);
            dfs(s, i + 1, open, remLeft, remRight, false, path, results);
            path.pop_back();
        }
    }
};
