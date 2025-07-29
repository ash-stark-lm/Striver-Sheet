class Solution {
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int min = 0;
    int cntFresh = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1)
          cntFresh++;
      }
    }

    while (!q.empty()) {
      int size = q.size();
      bool rotted = false;
      while (size--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dirs) {
          int i = x + dx;
          int j = y + dy;
          if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            q.push({i, j});
            grid[i][j] = 2;
            cntFresh--;
            rotted = true;
          }
        }
      }
      if (rotted)
        min++;
    }
    if (cntFresh == 0)
      return min;
    else
      return -1;
  }
};