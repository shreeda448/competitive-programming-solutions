#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

const int MAXN = 300005;
vector<int> adj[MAXN];
int sz[MAXN];
int dp[MAXN];

void dfs(int u, int p) {
  sz[u] = 1;
  vector<int> children;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      children.push_back(v);
    }
  }
  if (children.empty()) {
    dp[u] = 0;
  } else if (children.size() == 1) {
    dp[u] = sz[children[0]] - 1;
  } else {
    int v1 = children[0];
    int v2 = children[1];
    int option1 = (sz[v1] - 1) + dp[v2];
    int option2 = (sz[v2] - 1) + dp[v1];

    dp[u] = max(option1, option2);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << dp[1] << "\n";
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
