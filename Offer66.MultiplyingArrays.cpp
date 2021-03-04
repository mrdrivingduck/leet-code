/**
 * @author Mr Dk.
 * @version 2021/03/04
 */

/*
    给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是
    数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
    不能使用除法。 

    示例:
        输入: [1,2,3,4,5]
        输出: [120,60,40,30,24]

    提示：
        所有元素乘积之和不会溢出 32 位整数
        a.length <= 100000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
     1 a1 a2 a3 a4
    a0  1 a2 a3 a4
    a0 a1  1 a3 a4
    a0 a1 a2  1 a4
    a0 a1 a2 a3  1

    下三角和上三角可分别使用动态规划记录累积的乘积。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> result(a.size(), 1);
        int i;

        for (i = 1; i < (int) result.size(); i++) {
            result[i] = result[i - 1] * a[i - 1];
        }

        int temp = 1; // used for calculating temporary line result.
        i = result.size() - 2;
        while (i >= 0) {
            temp *= a[i + 1];
            result[i] *= temp;
            i--;
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> a;
    vector<int> arr;

    a = { 1,2,3,4,5 };
    arr = { 120,60,40,30,24 };
    assert(arr == s.constructArr(a));
    
    return 0;
}
