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
const ll M = 1e9 + 7;
ll powm(ll x, ll n) {
  x %= M;
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;
  int p = powm(x * x, n / 2);
  if (n % 2)
    return p * x % M;
  else
    return p;
}

void dfs(ll x, ll &sz, vector<bool> &vis, vector<vector<ll>> &adj) {
  vis[x] = true;
  sz++;
  for (auto &i : adj[x]) {
    if (!vis[i]) {
      dfs(i, sz, vis, adj);
    }
  }
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> adj(n + 1);
  vector<bool> vis(n + 1, false);
  for (int i = 0; i < n - 1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    if (x == 0) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  ll ans = 0;
  ll sz = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      sz = 0;
      dfs(i, sz, vis, adj);
      ans = (ans + powm(sz, k)) % M;
    }
  }
  ans = (powm(n, k) - ans + M) % M;
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
