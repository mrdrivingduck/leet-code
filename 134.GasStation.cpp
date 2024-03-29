/**
 * @author Mr Dk.
 * @version 2020.11.18
 */

/*
    There are N gas stations along a circular route, where the amount of gas
    at station i is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to
    travel from station i to its next station (i+1). You begin the journey
    with an empty tank at one of the gas stations.

    Return the starting gas station's index if you can travel around the
    circuit once in the clockwise direction, otherwise return -1.

    Note:

    If there exists a solution, it is guaranteed to be unique.
    Both input arrays are non-empty and have the same length.
    Each element in the input arrays is a non-negative integer.

    Example 1:
        Input: 
            gas  = [1,2,3,4,5]
            cost = [3,4,5,1,2]

        Output: 3

        Explanation:
            Start at station 3 (index 3) and fill up with 4 unit of gas.
            Your tank = 0 + 4 = 4
            Travel to station 4. Your tank = 4 - 1 + 5 = 8
            Travel to station 0. Your tank = 8 - 2 + 1 = 7
            Travel to station 1. Your tank = 7 - 3 + 2 = 6
            Travel to station 2. Your tank = 6 - 4 + 3 = 5
            Travel to station 3. The cost is 5. Your gas is just enough
            to travel back to station 3. Therefore, return 3 as the
            starting index.

    Example 2:
        Input: 
            gas  = [2,3,4]
            cost = [3,4,3]

        Output: -1

        Explanation:
            You can't start at station 0 or 1, as there is not enough gas
            to travel to the next station. Let's start at station 2 and
            fill up with 4 unit of gas. Your tank = 0 + 4 = 4
            Travel to station 0. Your tank = 4 - 3 + 2 = 3
            Travel to station 1. Your tank = 3 - 3 + 3 = 3
            You cannot travel back to station 2, as it requires 4 unit of
            gas but you only have 3. Therefore, you can't travel around
            the circuit once no matter where you start.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/gas-station
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历一次数组，依次将每一个点作为起点。基于一个事实：假设从 i 点出发，燃油不够到达
    j 点，那么从 i 到 j 中的任意一点出发，也肯定不能到达 j 点。原因在于，从 i 出发，
    如果能够到达下一个点，那么剩余燃油一定大于等于 0；如果在这个点加了油之后，还不够
    到达下一个点，那么从这个点空油箱出发，肯定也不能到达下一个点；依此类推，中间的所有
    点都不能到达 j 点。因此，下一个需要尝试的起点应当是 j + 1 (不必回溯)。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_gas = 0;
        int start_point = -1;

        // this loop is for finding a start point
        for (size_t i = 0; i < gas.size(); i++) {
            if (current_gas + gas[i] >= cost[i]) {
                current_gas = current_gas + gas[i] - cost[i];
                if (start_point == -1) {
                    start_point = i; // record the current start point
                }
            } else { // out of gas
                start_point = -1; // reset the start point
                current_gas = 0;  // empty the tank
            }
        }

        // a start point is efficient, then validate.
        if (start_point != -1) {
            for (int i = 0; i < start_point; i++) {
                if (current_gas + gas[i] >= cost[i]) {
                    current_gas = current_gas + gas[i] - cost[i];
                } else {
                    start_point = -1; // fail to pass the validation
                    break;            // exit immediatly
                }
            }
        }

        return start_point;
    }
};

int main() {
    Solution s;
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    cout << s.canCompleteCircuit(gas, cost) << endl;

    gas = { 2,3,4 };
    cost = { 3,4,3 };
    cout << s.canCompleteCircuit(gas, cost) << endl;

    gas = { 5,1,2,3,4 };
    cost = { 4,4,1,5,1 };
    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}