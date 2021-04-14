/**
 * @author Mr Dk.
 * @version 2021/04/14
 */

/*
    A trie (pronounced as "try") or prefix tree is a tree data structure
    used to efficiently store and retrieve keys in a dataset of strings.
    There are various applications of this data structure, such as
    autocomplete and spellchecker.

    Implement the Trie class:
        Trie() Initializes the trie object.
        void insert(String word) Inserts the string word into the trie.
        boolean search(String word) Returns true if the string word is
            in the trie (i.e., was inserted before), and false otherwise.
        boolean startsWith(String prefix) Returns true if there is a
            previously inserted string word that has the prefix prefix,
            and false otherwise.

    Example 1:
    Input
        ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
        [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
        [null, null, true, false, true, null, true]

    Explanation
        Trie trie = new Trie();
        trie.insert("apple");
        trie.search("apple");   // return True
        trie.search("app");     // return False
        trie.startsWith("app"); // return True
        trie.insert("app");
        trie.search("app");     // return True

    Constraints:
        1 <= word.length, prefix.length <= 2000
        word and prefix consist only of lowercase English letters.
        At most 3 * 104 calls in total will be made to insert, search, and startsWith.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    这个树结构还挺有意思。每个结点维护了 26 个 (所有小写字母) 指针，
    形成了一棵 26 叉树。每插入一个单词，意味着单词的每个字符都会成为
    一个结点存在于这颗树上。
    当需要进行前缀搜素时，只需要前缀串的每个字符从树根开始搜素即可。
    如果中途碰到空指针，那么前缀不存在。
    但是，在某个结点上，无法判断到底是存在树根到该结点的所有字符是一个
    单词还是只是一个单词的前缀子串。比如，如果树里插入了一个单词 apple，
    当遍历到第二个 p 结点时，将无法判断树里是否包含 app 单词，只能确认
    存在 app 前缀的字符串。因此每个结点内还要维护一个 bool，标识从根
    结点到当前结点的字符是否形成了一个完整的单词。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;

class Trie {
    Trie *next[26];
    bool word_exists;
public:
    /** Initialize your data structure here. */
    Trie() {
        for (long unsigned int i = 0; i < sizeof(next) / sizeof(Trie *); i++) {
            next[i] = NULL;
        }
        word_exists = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.length() > 0) {
            int index = word[0] - 'a';
            if (!next[index]) {
                next[index] = new Trie();
            }
            next[index]->insert(word.substr(1));
        } else {
            word_exists = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.length() > 0) {
            int index = word[0] - 'a';
            if (!next[index]) {
                return false;
            }
            return next[index]->search(word.substr(1));
        } else {
            return word_exists;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.length() > 0) {
            int index = prefix[0] - 'a';
            if (!next[index]) {
                return false;
            }
            return next[index]->startsWith(prefix.substr(1));
        } else {
            return true;
        }
    }

    ~Trie() {
        for (long unsigned int i = 0; i < sizeof(next) / sizeof(Trie *); i++) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie* tree = new Trie();

    tree->insert("apple");
    assert(true == tree->search("apple"));
    assert(false == tree->search("app"));
    assert(true == tree->startsWith("app"));
    tree->insert("app");
    assert(true == tree->search("app"));

    delete tree;

    return 0;
}
