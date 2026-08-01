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

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  vector<int> ans(n - 1, -1);
  int target_node = -1;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() >= 3) {
      target_node = i;
      break;
    }
  }
  int cur = 0;
  if (target_node != -1) {
    for (auto edge : adj[target_node]) {
      if (cur < 3) {
        ans[edge.second] = cur++;
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (ans[i] == -1) {
      ans[i] = cur++;
    }
    cout << ans[i] << "\n";
  }
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
