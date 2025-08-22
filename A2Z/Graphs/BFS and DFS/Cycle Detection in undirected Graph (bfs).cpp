class Solution {
  bool BFS(int src, vector<int> &vis, vector<vector<int>> &adj) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty()) {
      int node = q.front().first;
      int par = q.front().second;
      q.pop();

      for (auto &child : adj[node]) {
        if (!vis[child]) {
          q.push({child, node});
          vis[child] = 1;
        } else if (child != par) {
          // already visited and not the parent -> cycle
          return true;
        }
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<vector<int>> &edges) {
    // create adj list
    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (BFS(i, vis, adj))
          return true;
      }
    }
    return false;
  }
};
