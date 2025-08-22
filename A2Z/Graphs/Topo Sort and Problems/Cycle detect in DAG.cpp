// Using DFS

class Solution {

  bool DFS(int node, vector<vector<int>> &adj, vector<int> &vis,
           vector<int> &path) {
    vis[node] = 1;
    path[node] = 1;

    for (auto &child : adj[node]) {
      if (path[child])
        return true; // cycle hai
      if (!vis[child] && DFS(child, adj, vis, path))
        return true;
    }

    path[node] = 0;
    return 0;
  }

public:
  bool isCyclic(int n, vector<vector<int>> &edges) {
    // code here

    // need vis and path array
    vector<vector<int>> adj(n);
    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    vector<int> path(n, 0); // to track if that node is in current path
    // logic if the same node comes more than once in the curr path -> cycle
    // present

    for (int i = 0; i < n; i++) {
      if (!vis[i] && DFS(i, adj, vis, path))
        return true;
    }
    return false;
  }
};

// using kahns algo
class Solution {

public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V);

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);

      indegree[v]++;
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      ans.push_back(node);

      for (auto &child : adj[node]) {
        indegree[child]--;
        if (indegree[child] == 0)
          q.push(child);
      }
    }

    return ans.size() != V; // means cycle present
  }
};
