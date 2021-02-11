/**
 * @author Mr Dk.
 * @version 2021/02/11
 */

/*
    Design a class to find the kth largest element in a stream. Note that
    it is the kth largest element in the sorted order, not the kth distinct
    element.

    Implement KthLargest class:
        KthLargest(int k, int[] nums) Initializes the object with the
        integer k and the stream of integers nums.
        int add(int val) Returns the element representing the kth
        largest element in the stream.

    Example 1:
        Input
            ["KthLargest", "add", "add", "add", "add", "add"]
            [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
        Output
            [null, 4, 5, 5, 8, 8]
        Explanation
            KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
            kthLargest.add(3);   // return 4
            kthLargest.add(5);   // return 5
            kthLargest.add(10);  // return 5
            kthLargest.add(9);   // return 8
            kthLargest.add(4);   // return 8

    Constraints:
        1 <= k <= 104
        0 <= nums.length <= 104
        -104 <= nums[i] <= 104
        -104 <= val <= 104
        At most 104 calls will be made to add.
        It is guaranteed that there will be at least k elements in the
        array when you search for the kth element.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护一个长度为 k 的小顶堆，堆顶元素即为第 k 大的元素。如果队列内元素数量超出
    k 个，那么需要将堆大小调整至 k。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class KthLargest {
private:
    int k;
    vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        std::make_heap(nums.begin(), nums.end(), std::greater<int>());
        while ((int) nums.size() > k) {
            std::pop_heap(nums.begin(), nums.end(), std::greater<int>());
            nums.pop_back();
        }

        this->k = k;
        this->nums = nums;
    }
    
    int add(int val) {
        nums.push_back(val);
        std::push_heap(nums.begin(), nums.end(), std::greater<int>());

        if ((int) nums.size() > k) {
            std::pop_heap(nums.begin(), nums.end(), std::greater<int>());
            nums.pop_back();
        }

        return nums[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    vector<int> nums;
    
    nums = { 4,5,8,2 };
    KthLargest kthLargest(3, nums);
    assert(4 == kthLargest.add(3));   // return 4
    assert(5 == kthLargest.add(5));   // return 5
    assert(5 == kthLargest.add(10));  // return 5
    assert(8 == kthLargest.add(9));   // return 8
    assert(8 == kthLargest.add(4));   // return 8

    // nums = {};
    // KthLargest kthLargest(1, nums);
    // assert(-3 == kthLargest.add(-3));   // return -3
    // assert(-2 == kthLargest.add(-2));   // return -2
    // assert(-2 == kthLargest.add(-4));  // return -2
    // assert(0 == kthLargest.add(0));   // return 0
    // assert(4 == kthLargest.add(4));   // return 4

    return 0;
}
