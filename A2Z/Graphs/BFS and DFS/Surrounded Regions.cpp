class Solution {
  vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  void solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    // take boundary o's and traverse all o's conneceted to it that all cant
    // be surrounded

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((i == 0 || i == m - 1 || j == n - 1 || j == 0) &&
            board[i][j] == 'O') {
          q.push({i, j});
          board[i][j] = 'B';
        }
      }
    }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (auto &[dx, dy] : dir) {
        int x = i + dx;
        int y = j + dy;

        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
          board[x][y] = 'B';
          q.push({x, y});
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'B') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};