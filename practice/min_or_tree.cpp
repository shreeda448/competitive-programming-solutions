#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

struct Edge {
  int u, v;
  ll w;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> all_edges;
  for (int i = 0; i < m; i++) {
    int x, y;
    ll z;
    cin >> x >> y >> z;
    all_edges.push_back({x, y, z});
  }
  int allowed_mask = (1 << 30) - 1;
  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1, false);
  for (int bit = 29; bit >= 0; bit--) {
    int test_mask = allowed_mask ^ (1 << bit);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      vis[i] = 0;
    }
    for (auto edge : all_edges) {
      if ((edge.w | test_mask) == test_mask) {
        adj[edge.u].push_back(edge.v);
        adj[edge.v].push_back(edge.u);
      }
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;

    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      cnt++;
      for (int v : adj[u]) {
        if (!vis[v]) {
          vis[v] = true;
          // Distance/State tracking here

          q.push(v);
        }
      }
    }
    if (cnt == n) {
      allowed_mask = test_mask;
    }
  }
  cout << allowed_mask << nline;
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
