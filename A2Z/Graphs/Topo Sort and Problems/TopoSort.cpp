// Using DFS
class Solution {
public:
  void DFS(int node, vector<vector<int>> &adj, vector<int> &vis,
           stack<int> &st) {
    vis[node] = 1;

    for (auto child : adj[node]) {
      if (!vis[child]) {
        DFS(child, adj, vis, st);
      }
    }
    st.push(node);
  }
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adj(V);

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
    }
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        DFS(i, adj, vis, st);
      }
    }
    vector<int> ans;

    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};
// Using BFS->  Kahn's Algorithm
class Solution {
public:
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    // code here
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

    return ans;
  }
};