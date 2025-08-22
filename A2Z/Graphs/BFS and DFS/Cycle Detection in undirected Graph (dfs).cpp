// ques link:->
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  bool DFS(int node, int parent, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto child : adj[node]) {
      if (!vis[child]) {
        if (DFS(child, node, vis, adj))
          return true;
      } else if (child != parent) {
        // found a back edge → cycle
        return true;
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
        if (DFS(i, -1, vis, adj))
          return true;
      }
    }
    return false;
  }
};
