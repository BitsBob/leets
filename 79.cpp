#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    if (idx == word.size()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
    if (board[i][j] != word[idx]) return false;

    char done = board[i][j];
    board[i][j] = '.';

    bool found = dfs(board, word, i+1, j, idx+1) ||
                 dfs(board, word, i-1, j, idx+1) ||
                 dfs(board, word, i, j+1, idx+1) ||
                 dfs(board, word, i, j-1, idx+1);

    board[i][j] = done;
    return found;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        reverse(word.begin(), word.end());

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        
        return false;
    }
};
