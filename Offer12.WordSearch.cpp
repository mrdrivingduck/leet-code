/**
 * @author Mr Dk.
 * @version 2020/10/21
 */

/*
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
    如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面
    的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

    [["a","b","c","e"],
    ["s","f","c","s"],
    ["a","d","e","e"]]

    但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行
    第二个格子之后，路径不能再次进入这个格子。

    示例 1：

    输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
        word = "ABCCED"
    输出：true

    示例 2：

    输入：board = [["a","b"],["c","d"]], word = "abcd"
    输出：false

    提示：

    1 <= board.length <= 200
    1 <= board[i].length <= 200

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return false;
        }
        vector<vector<bool>> map(board.size(), vector<bool>());
        for (int i = 0; i < map.size(); i++) {
            map[i].resize(board[0].size(), true);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    if (search(board, map, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, vector<vector<bool>>& map, int i, int j, int index, string word) {
        map[i][j] = false;
        index++;
        if (index == word.length()) {
            return true;
        }

        if (i - 1 >= 0 && map[i-1][j] && word[index] == board[i-1][j]) {
            if (search(board, map, i-1, j, index, word)) return true;
        }
        if (i + 1 < board.size() && map[i+1][j] && word[index] == board[i+1][j]) {
            if (search(board, map, i+1, j, index, word)) return true;
        }
        if (j - 1 >= 0 && map[i][j-1] && word[index] == board[i][j-1]) {
            if (search(board, map, i, j-1, index, word)) return true;
        }
        if (j + 1 < board[0].size() && map[i][j+1] && word[index] == board[i][j+1]) {
            if (search(board, map, i, j+1, index, word)) return true;
        }

        map[i][j] = true; // 回溯
        return false;
    }
};

int main()
{
    // vector<vector<char>> board = {
    //     { 'A', 'B', 'C', 'E' },
    //     { 'S', 'F', 'C', 'S' },
    //     { 'A', 'D', 'E', 'E' }
    // };

    vector<vector<char>> board = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'E', 'S' },
        { 'A', 'D', 'E', 'E' }
    };

    Solution s;
    if (s.exist(board, /*"ABCCED"*/ "ABCESEEEFS")) {
        cout << "Exist" << endl;
    } else {
        cout << "Not exist" << endl;
    }

    return 0;
}