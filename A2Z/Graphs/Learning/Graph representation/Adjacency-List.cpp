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

  vector<int> adj[m + 1];

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  cout << "Adjacency List:\n";
  for (int i = 1; i <= m; i++) {
    cout << i << ": ";
    for (int neighbor : adj[i]) {
      cout << neighbor << " ";
    }
    cout << "\n";
  }

  return 0;
}