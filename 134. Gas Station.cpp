class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;

        for (int i = 0; i < (int)gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            // Can't reach i + 1 from start, so no station in [start, i] works
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // If the total gas covers the total cost, the last start found works
        return total < 0 ? -1 : start;
    }
};
