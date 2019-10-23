/**
 * @author Mr Dk.
 * @version 2019.10.23
 */

/*
    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example:

    board =
    [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/word-search
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    构造一张和字母表同样大小的表，用于记录字母表对应位置是否已被访问过。
    算法采用深度优先遍历 (DFS)

    首先找到字符串首字母在字母表中的位置
    从该位置开始，依次向上、下、左、右进行探索
    如果满足探索条件，则递归进入下一个位置

    递归体：
        1. 进入前提：当前字符已经在字符串中出现
           那么首先将该位置记为被访问
           如果这已经是字符串的最后一个字符，则直接向上一级返回成功
        2. 依次探索上、下、左、右位置与下一个字符
           如果 OJBK，那么递归进入下一个位置
        3. 如果四个位置都无法再递归，说明走入了死胡同
           向上一级报告失败
           * 最重要的是，要清空该位置的访问记录
    
    实现细节：
        为节省空间，递归时，访问记录表以引用形式传递
        因此，访问失败回溯时，一定要清空失败探索中增加的访问记录
 */

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::size_t;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return false;
        }

        vector<vector<bool>> visited;
        int height = 0;
        int width = 0;
        visited.reserve((height = board.size()));
        for (size_t i = 0; i < board.size(); i++) {
            vector<bool> line = vector<bool>((width = board[i].size()), false);
            visited.push_back(line);
        }

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, visited, word, 0, i, j, height, width)) {
                        return true;
                    }
                }
            }
        } 

        return false;
    }

    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, string &word, int idx, int i, int j, int &height, int &width) {
        // word[idx] has already discovered
        visited[i][j] = true; // visit this position ()

        // last character - exit of recursion
        if (((size_t) idx) >= word.length() - 1) { // ?
            return true;
        }

        // next character
        idx++;

        // try top
        // not at edge && not visited && character discovered
        if (i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == word[idx]) {
            if (search(board, visited, word, idx, i - 1, j, height, width)) {
                return true;
            }
        }
        // try bottom
        // not at edge && not visited && character discovered
        if (i + 1 < height && !visited[i + 1][j] && board[i + 1][j] == word[idx]) {
            if (search(board, visited, word, idx, i + 1, j, height, width)) {
                return true;
            }
        }
        // try left
        // not at edge && not visited && character discovered
        if (j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == word[idx]) {
            if (search(board, visited, word, idx, i, j - 1, height, width)) {
                return true;
            }
        }
        // try right
        // not at edge && not visited && character discovered
        if (j + 1 < width && !visited[i][j + 1] && board[i][j + 1] == word[idx]) {
            if (search(board, visited, word, idx, i, j + 1, height, width)) {
                return true;
            }
        }

        // all try fail
        visited[i][j] = false; // unvisit this position for tracing back
        return false;
    }
};

int main() {

    vector<char> line1 = { 'A', 'B', 'C', 'E' };
    vector<char> line2 = { 'S', 'F', 'C', 'S' };
    vector<char> line3 = { 'A', 'D', 'E', 'E' };
    vector<vector<char>> board = vector<vector<char>>();
    board.push_back(line1);
    board.push_back(line2);
    board.push_back(line3);

    Solution solution = Solution();
    cout << solution.exist(board, "ABCCED") << endl;

    return 0;
}
