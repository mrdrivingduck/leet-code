/**
 * @author Mr Dk.
 * @version 2020.11.15
 */

/*
    Given two arrays arr1 and arr2, the elements of arr2 are distinct,
    and all elements in arr2 are also in arr1.

    Sort the elements of arr1 such that the relative ordering of items
    in arr1 are the same as in arr2. Elements that don't appear in arr2 
    hould be placed at the end of arr1 in ascending order.

    Example 1:
        Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
        Output: [2,2,2,1,4,3,3,9,6,7,19]

    Constraints:
        arr1.length, arr2.length <= 1000
        0 <= arr1[i], arr2[i] <= 1000
        Each arr2[i] is distinct.
        Each arr2[i] is in arr1.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/relative-sort-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    弄了一个倒排索引，当要比较的数都出现在 distinct 集合中时，比较倒排
    索引中的值；如果一个数出现在 distinct 中，则这个数较小；如果两个数
    都不存在于 distinct 中，那么直接比较这两个数的数值大小。

    C++ 的比较函数如何自定义参数列表呢？似乎不行。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::set;

int reversed_index[1001] = { 2000 };

bool comp(int a, int b) {
    if (reversed_index[a] < 2000 || reversed_index[b] < 2000) {
        return reversed_index[a] < reversed_index[b];
    } else {
        return a < b;
    }
}

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (size_t i = 1; i < sizeof(reversed_index) / sizeof(int); i++) {
            reversed_index[i] = 2000;
        }
        for (size_t i = 0; i < arr2.size(); i++) {
            reversed_index[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), comp);
        return arr1;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    vector<int> arr2 = { 2,1,4,3,9,6 };
    vector<int> res = s.relativeSortArray(arr1, arr2);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
