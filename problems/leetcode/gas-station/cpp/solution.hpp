class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0, steps = 0, start = 0, next = 0;
        while (start < gas.size()) {
            if (balance < 0) {
                balance -= (gas[start] - cost[start]);
                steps--;
                start++;
                continue;
            }
            if (steps == gas.size()) {
                return start;
            }
            balance += (gas[next] - cost[next]);
            steps++;
            next = (next + 1) % gas.size();
        }
        return -1;
    }
};
