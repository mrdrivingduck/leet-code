/**
 * @author Mr Dk.
 * @version 2020/11/22
 */

/*
    如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数
    值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排
    序之后中间两个数的平均值。

    例如，
        [2,3,4] 的中位数是 3
        [2,3] 的中位数是 (2 + 3) / 2 = 2.5

    设计一个支持以下两种操作的数据结构：
        void addNum(int num) - 从数据流中添加一个整数到数据结构中。
        double findMedian() - 返回目前所有元素的中位数。

    示例 1：
        输入：
            ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
            [[],[1],[2],[],[3],[]]
        输出：[null,null,null,1.50000,null,2.00000]

    示例 2：
        输入：
            ["MedianFinder","addNum","findMedian","addNum","findMedian"]
            [[],[2],[],[3],[]]
        输出：[null,null,2.00000,null,2.50000]

    限制：
        最多会对 addNum、findMedian 进行 50000 次调用。

    注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    设置两个堆，分别保存序列的前一半的数字和后一半的数字：前一半的数字用大顶堆保存，
    后一半的数字用小顶堆保存，保证前一半数字的数量 (大顶堆) 时刻与后一半数字的数量
    (小顶堆) 相等或大于 1。
    中位数的值为大顶堆 (前一半数字) 堆顶 (如果大顶堆比小顶堆的 size 大 1)；或为
    两个堆顶的平均值 (如果大顶堆与小顶堆的 size 相等)。
*/

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

class MedianFinder {
private:
    priority_queue<int> small_part;
    priority_queue<int, vector<int>, std::greater<int>> bigger_part;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (!small_part.empty()) {
            // judge to insert into smaller half or bigger half
            int top = small_part.top();
            if (num < top) {
                small_part.push(num);
            } else {
                bigger_part.push(num);
            }

            // maintain size(smaller) == size(bigger) || delta = 1
            if (small_part.size() > bigger_part.size() + 1) {
                top = small_part.top();
                small_part.pop();
                bigger_part.push(top);
            } else if (bigger_part.size() > small_part.size()) {
                top = bigger_part.top();
                bigger_part.pop();
                small_part.push(top);
            }
        } else {
            // initial add
            small_part.push(num);
        }
    }
    
    double findMedian() {
        if (bigger_part.size() == small_part.size()) {
            int mid1 = small_part.top();
            int mid2 = bigger_part.top();
            return ((double) (mid1 + mid2)) / 2;
        } else {
            return small_part.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    delete obj;

    obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    obj->addNum(-2);
    cout << obj->findMedian() << endl;
    obj->addNum(-3);
    cout << obj->findMedian() << endl;
    obj->addNum(-4);
    cout << obj->findMedian() << endl;
    obj->addNum(-5);
    cout << obj->findMedian() << endl;
    delete obj;

    return 0;
}