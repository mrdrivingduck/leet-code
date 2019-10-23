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
