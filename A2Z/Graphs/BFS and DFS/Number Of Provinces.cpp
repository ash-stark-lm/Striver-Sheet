// ques link;-> https://leetcode.com/problems/number-of-provinces/

class Solution {

  void DFS(int node, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto &child : adj[node]) {
      if (!vis[child])
        DFS(child, vis, adj);
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && i != j) {
          adj[i].push_back(j);
        }
      }
    }
    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        cnt++;
        DFS(i, vis, adj);
      }
    }
    return cnt;
  }
};