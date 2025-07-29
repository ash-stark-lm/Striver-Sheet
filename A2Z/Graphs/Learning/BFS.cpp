#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define inputarr(arr, n)                                                       \
  for (int i = 0; i < n; i++)                                                  \
    cin >> arr[i];
#define endl "\n"
#define pb push_back
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define vi(n)                                                                  \
  vector<int> v(n);                                                            \
  inputarr(v, n);

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V = 5; // Number of nodes
  vector<vector<int>> adj(V);

  // Undirected graph edges
  vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {2, 4}, {2, 3}};
  // 0 based

  /*
      0 - 1
      |   |
      4 - 2
          |
          3
  */

  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(V, 0);

  // BFS implementation

  queue<int> q;
  q.push(0);
  vis[0] = 1;
  vector<vector<int>> bfs;

  while (!q.empty()) {
    int size = q.size();
    vector<int> temp;
    while (size--) {

      int node = q.front();
      q.pop();
      temp.push_back(node);
      for (auto &child : adj[node]) {
        if (!vis[child]) {
          vis[child] = 1;
          q.push(child);
        }
      }
    }
    bfs.push_back(temp);
  }

  for (auto &level : bfs) {
    for (auto &node : level) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}
