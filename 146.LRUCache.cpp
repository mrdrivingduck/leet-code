/**
 * @author Mr Dk.
 * @version 2021/03/18
 */

/*
    Design a data structure that follows the constraints of a Least
    Recently Used (LRU) cache.

    Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive
    size capacity.
    int get(int key) Return the value of the key if the key exists,
    otherwise return -1.
    void put(int key, int value) Update the value of the key if the
    key exists. Otherwise, add the key-value pair to the cache. If
    the number of keys exceeds the capacity from this operation,
    evict the least recently used key.

    Follow up:
        Could you do get and put in O(1) time complexity?

    Example 1:
    Input
        ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        lRUCache.get(1);    // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        lRUCache.get(2);    // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        lRUCache.get(1);    // return -1 (not found)
        lRUCache.get(3);    // return 3
        lRUCache.get(4);    // return 4
     

    Constraints:
        1 <= capacity <= 3000
        0 <= key <= 3000
        0 <= value <= 104
        At most 3 * 104 calls will be made to get and put.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/lru-cache
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用 hash table 维护键值对，值为双向链表的迭代器。在双向链表中维护实际
    的键值对。在查找时，通过 key 找到双向链表迭代器，从而访问到链表节点；
    在淘汰时，通过链表的最后一个节点拿到 key，从而在 hash table 中移除节点，
    在链表中也移除节点。
 */

#include <cassert>

#include <iostream>
#include <list>
#include <unordered_map>
using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

struct node {
    int key;
    int value;
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<node>::iterator> map;
    list<node> nodes;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        map.reserve(capacity);
    }
    
    int get(int key) {
        unordered_map<int, list<node>::iterator>::iterator iter = map.find(key);
        if (iter == map.end()) {
            return -1;
        }
        
        node value = *iter->second;
        nodes.erase(iter->second);
        nodes.push_front(value);
        iter->second = nodes.begin();
        return value.value;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            if ((size_t) capacity == nodes.size()) {
                node last = nodes.back();
                map.erase(last.key);
                nodes.pop_back();
            }

            node n = { key, value };
            nodes.push_front(n);
            map.insert(std::make_pair(key, nodes.begin()));
        } else {
            nodes.begin()->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    assert(1 == obj->get(1));
    obj->put(3, 3);
    assert(-1 == obj->get(2));
    obj->put(4, 4);
    assert(-1 == obj->get(1));
    assert(3 == obj->get(3));
    assert(4 == obj->get(4));

    delete obj;

    return 0;
}
