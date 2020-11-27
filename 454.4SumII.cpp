/**
 * @author Mr Dk.
 * @version 2020/11/27
 */

/*
    Given four lists A, B, C, D of integer values, compute how many tuples
    (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

    To make problem a bit easier, all A, B, C, D have same length of N where
    0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the
    result is guaranteed to be at most 231 - 1.

    Example:

    Input:
        A = [ 1, 2]
        B = [-2,-1]
        C = [-1, 2]
        D = [ 0, 2]

    Output:
        2

    Explanation:
        The two tuples are:
            1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
            2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/4sum-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    对于此类题目，由于不需要得到最终的结果序列，而是只需要一个结果。可以将原有的 1-N 个数的和
    拆分为 1-T 的和以及 T+1 - N 的和。这样，原先的时间复杂度 O(n^N) 就降到了 O(n^T) +
    (n^(N-T-1))。在上面的例子中，O(n^4) 降至 O(n^2)。

    对于四个元素的和，可以先迭代前两个数组，计算前两个元素的和，并将和值对应的数量放在一个 hash
    table 中。然后再迭代后两个数组计算和，并查看 hash table 中是否存在和的相反数。如果有，说明
    存在可以组合的情况，最终结果中累加上 hash table 中的组合数量。

    注意 STL 中 map 与 unordered_map 的区别：STL map 相当于 JDK 中的 TreeMap，由红黑树
    结构维护了顺序关系；而 unordered_map 内维护了一个 hash 桶，相当于 JDK 中的 HashMap。
    在这里显然用 unordered_map 更合适。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::pair;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> two_sum;

        for (size_t i = 0; i < A.size(); i++) {
            for (size_t j = 0; j < B.size(); j++) {
                int key = A[i] + B[j];
                unordered_map<int, int>::iterator iter = two_sum.find(key);
                if (iter == two_sum.end()) {
                    two_sum.insert(pair<int, int> (key, 1));
                } else {
                    iter->second++;
                }
            }
        }

        int result = 0;

        for (size_t i = 0; i < C.size(); i++) {
            for (size_t j = 0; j < D.size(); j++) {
                int key = -(C[i] + D[j]);
                unordered_map<int, int>::iterator iter = two_sum.find(key);
                if (iter != two_sum.end()) {
                    result += iter->second;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;    
    vector<int> A, B, C, D;

    A = { 1, 2 };
    B = { -2, -1 };
    C = { -1, 2 };
    D = { 0, 2 };

    cout << s.fourSumCount(A, B, C, D) << endl;

    return 0;
}
