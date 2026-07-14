#include <bits/stdc++.h>
#include <list>
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> group;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    group.resize(k);
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      group[j] = x;
      if (j > 0) {
        adj[x].push_back(group[j - 1]);
        adj[group[j - 1]].push_back(x);
      }
    }
  }
  vector<int> ans(n + 1);
  vector<bool> vis(n + 1, false);
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;

    vector<int> comp;
    vis[i] = true;
    q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      comp.push_back(u);

      for (int v : adj[u]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }

    for (int x : comp)
      ans[x] = comp.size();
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << nline;
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
