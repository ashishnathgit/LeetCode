// Difficulty: Medium | Time: O(n+m) | Space: O(1) | Pattern: String | Use: Comparing software versions in package managers
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int m = version1.size(), n = version2.size();

        // Compare one revision at a time; a missing revision counts as 0
        while (i < m || j < n) {
            int a = 0, b = 0;
            while (i < m && version1[i] != '.') a = a * 10 + (version1[i++] - '0');
            while (j < n && version2[j] != '.') b = b * 10 + (version2[j++] - '0');

            if (a < b) return -1;
            if (a > b) return 1;

            // Skip the dots
            i++;
            j++;
        }
        return 0;
    }
};
