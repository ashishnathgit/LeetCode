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

        while (total < n) {
            // Refill only when the leftovers from earlier calls are used up
            if (bufPos == bufCount) {
                bufCount = read4(buf4);
                bufPos = 0;
                if (bufCount == 0) break;  // End of file
            }
            buf[total++] = buf4[bufPos++];
        }
        return total;
    }

private:
    // Characters read by read4 but not returned yet are kept between calls
    char buf4[4];
    int bufPos = 0;
    int bufCount = 0;
};
