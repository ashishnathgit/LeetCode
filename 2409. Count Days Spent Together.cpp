#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Both are in town from the later arrival to the earlier departure
        int start = dayOfYear(max(arriveAlice, arriveBob));
        int end = dayOfYear(min(leaveAlice, leaveBob));
        return max(0, end - start + 1);
    }

private:
    // Convert "MM-DD" to day number in a non-leap year (1..365)
    int dayOfYear(const string& date) {
        static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;
        for (int m = 0; m < month - 1; m++) {
            total += daysInMonth[m];
        }
        return total;
    }
};
