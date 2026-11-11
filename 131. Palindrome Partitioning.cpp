// Difficulty: Medium | Time: O(n·2ⁿ) | Space: O(n²) | Pattern: Backtracking | Use: Enumerating every way to segment text
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        // Step 1: isPal[i][j] tells whether s[i..j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                isPal[i][j] = s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1]);
            }
        }

        // Step 2: Backtrack, cutting only at palindromic pieces
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, isPal, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, const vector<vector<bool>>& isPal,
                   vector<string>& current, vector<vector<string>>& result) {
        if (start == (int)s.size()) {
            result.push_back(current);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end) {
            if (!isPal[start][end]) continue;
            current.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, isPal, current, result);
            current.pop_back();
        }
    }
};
