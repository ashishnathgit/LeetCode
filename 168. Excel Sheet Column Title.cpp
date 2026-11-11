// Difficulty: Easy | Time: O(log n) | Space: O(1) | Pattern: Math | Use: Spreadsheet column labels
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;

        // Like base 26, but digits run 1..26 (A..Z) instead of 0..25,
        // so subtract 1 before taking each digit
        while (columnNumber > 0) {
            columnNumber--;
            title += char('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(title.begin(), title.end());
        return title;
    }
};
