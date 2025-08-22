class Solution {
  int m, n;
  vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  int numEnclaves(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1) {
          q.push({i, j});
          grid[i][j] = 2;
        }
      }
    }
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (auto &[dx, dy] : dir) {
        int x = i + dx;
        int y = j + dy;
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
          grid[x][y] = 2;
          q.push({x, y});
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          cnt++;
        else if (grid[i][j] == 2)
          grid[i][j] = 1;
      }
    }
    return cnt;
  }
};