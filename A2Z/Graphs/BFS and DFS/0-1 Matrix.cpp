class Solution {
  vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> newMat(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0) {
          newMat[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (auto &[dx, dy] : dir) {
        int x = i + dx;
        int y = j + dy;
        if (x >= 0 && x < n && y >= 0 && y < m && newMat[x][y] == -1) {
          newMat[x][y] = newMat[i][j] + 1;
          q.push({x, y});
        }
      }
    }

    return newMat;
  }
};