/*
 * Valid Sudoku
 * */

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool num[9];

    for (int i = 0; i < 9; ++i) {
      memset(num, 0, sizeof(num));
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') continue;
        int idx = board[i][j] - '1';
        if (num[idx]) return false;
        num[idx] = true;
      }
    }
    
    for (int i = 0; i < 9; ++i) {
      memset(num, 0, sizeof(num));
      for (int j = 0; j < 9; ++j) {
        if (board[j][i] == '.') continue;
        int idx = board[j][i] - '1';
        if (num[idx]) return false;
        num[idx] = true;
      }
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        memset(num, 0, sizeof(num));
        for (int m = 0; m < 3; ++m) {
          for(int n = 0; n < 3; ++n) {
            if (board[i+m][j+n] == '.') continue;
            int idx = board[i+m][j+n] - '1';
            if (num[idx]) return false;
            num[idx] = true;
          }
        } 
      }
    }
    return true;
  }
};
