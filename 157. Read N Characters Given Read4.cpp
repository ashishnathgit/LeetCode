// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Design | Use: Reading files through fixed-size block APIs
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        char buf4[4];

        while (total < n) {
            int count = read4(buf4);
            if (count == 0) break;  // End of file

            // Copy only as many characters as we still need
            int toCopy = min(count, n - total);
            for (int i = 0; i < toCopy; ++i) buf[total++] = buf4[i];
        }
        return total;
    }
};
