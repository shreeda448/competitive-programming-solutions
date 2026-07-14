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

void dfs(int u, vector<int> &dp, int n, vector<vector<pair<int, int>>> &edg,
         vector<int> &id) {
  for (auto it : edg[u]) {
    if (dp[it.first] == 0) {
      dp[it.first] = dp[u] + (it.second <= id[u]);
      id[it.first] = it.second;
      dfs(it.first, dp, n, edg, id);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  vector<int> idx(n + 1);
  vector<vector<pair<int, int>>> edges(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back({v, i});
    edges[v].push_back({u, i});
  }
  dp[1] = 1;
  dfs(1, dp, n, edges, idx);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, dp[i]);
  cout << ans << '\n';
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
