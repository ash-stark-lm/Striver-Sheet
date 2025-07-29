
// ques
// link;->https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
class Solution {
  void dfs(int node, vector<int> &vis, vector<vector<int>> &adj,
           vector<int> &temp) {
    vis[node] = 1;
    temp.push_back(node);
    for (auto &child : adj[node]) {
      if (!vis[child]) {
        dfs(child, vis, adj, temp);
      }
    }
  }

public:
  vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
    // code here
    int n = edges.size();
    vector<vector<int>> adj(V);
    vector<int> vis(V, 0);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        vector<int> temp;
        dfs(i, vis, adj, temp);
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
      }
    }
    return ans;
  }
};
