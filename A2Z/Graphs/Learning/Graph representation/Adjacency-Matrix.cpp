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

  int m, n;
  cin >> m >> n; // m = number of nodes, n = number of edges

  // Create an m+1 x m+1 matrix (1-based indexing)
  vector<vector<int>> adj(m + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    // Undirected graph
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  cout << "Adjacency Matrix:\n";
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}