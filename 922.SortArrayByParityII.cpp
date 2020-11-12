/**
 * @author Mr Dk.
 * @version 2020.11.12
 */

/*
    Given an array A of non-negative integers, half of the integers
    in A are odd, and half of the integers are even.

    Sort the array so that whenever A[i] is odd, i is odd; and whenever
    A[i] is even, i is even.

    You may return any answer array that satisfies this condition.

    Example 1:

    Input: [4,2,5,7]
    Output: [4,5,2,7]
    Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
     
    Note:

    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    两个指针分别指向奇数位置和偶数位置，并定位到首个不符合要求的位置，然后互换。
    注意 while 中的边界条件！！！
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        size_t even_index = 0;
        size_t odd_index = 1;
        vector<int> answer(A.begin(), A.end());

        while (even_index < answer.size() && odd_index < answer.size()) {
            while (even_index < answer.size() && answer[even_index] % 2 == 0) {
                even_index += 2;
            }
            while (odd_index < answer.size() && answer[odd_index] % 2 == 1) {
                odd_index += 2;
            }
            if (even_index >= answer.size() || odd_index >= answer.size()) {
                break;
            }

            int swap = answer[even_index];
            answer[even_index] = answer[odd_index];
            answer[odd_index] = swap;
        }

        return answer;
    }
};

int main() {

    vector<int> seq = { 4,2,5,7 };
    Solution s;
    vector<int> answer = s.sortArrayByParityII(seq);
    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
