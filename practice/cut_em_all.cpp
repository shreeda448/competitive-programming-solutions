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

ll dfs(int node, int parent, vector<vector<int>> &adj, ll &ans) {
  ll f = 1;
  for (auto x : adj[node]) {
    if (x != parent) {
      f += dfs(x, node, adj, ans);
    }
  }
  if (parent != -1 && f % 2 == 0) {
    ans++;
  }
  return f;
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n & 1) {
    cout << -1 << nline;
    return;
  }
  ll ans = 0;
  dfs(1, -1, adj, ans);
  cout << ans << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
