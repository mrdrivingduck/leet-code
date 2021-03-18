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
    用 hash table 维护键值对，并在值中额外维护两个指针，从而形成以访问先后顺序
    为顺序的双向链表。当对结点进行访问操作时，通过 hash table 拿到对结点的引用，
    将结点移出链表并重新插入到链表头部。当需要进行淘汰操作时，将链表尾部的结点
    移除链表并从 hash table 中移除。
 */

#include <cassert>

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;

struct node {
    int key;
    int value;
    node *prev;
    node *next;
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, node> map;
    node head;
    node tail;

    void link_head(node *p) {
        p->next = head.next;
        head.next = p;
        p->prev = p->next->prev;
        p->next->prev = p;
    }

    void unlink(node *p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head.prev = NULL;
        head.next = &tail;
        tail.next = NULL;
        tail.prev = &head;
    }
    
    int get(int key) {
        unordered_map<int, node>::iterator iter = map.find(key);
        if (iter == map.end()) {
            return -1;
        }
        
        node *p = &iter->second;
        unlink(p);
        link_head(p);
        return p->value;
    }
    
    void put(int key, int value) {
        unordered_map<int, node>::iterator iter = map.find(key);
        if (iter != map.end()) {
            node *p = &iter->second;
            unlink(p);
            link_head(p);
            p->value = value;
        } else {
            iter = map.insert(std::pair<int, node>(key, { key, value, NULL, NULL })).first;
            link_head(&iter->second);

            if ((int) map.size() > capacity) {
                node *p = tail.prev;
                unlink(p);
                map.erase(p->key);
            }
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
