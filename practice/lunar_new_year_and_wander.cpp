#include <bits/stdc++.h>
#include <set>
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
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> res;
  set<int> st;
  vector<bool> vis(n + 1, false);
  st.insert(1);
  vis[1] = true;
  while (!st.empty()) {
    int u = *st.begin();
    res.push_back(u);
    st.erase(st.begin());
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        // Distance/State tracking here
        st.insert(v);
      }
    }
  }
  for (auto x : res) {
    cout << x << " ";
  }
  cout << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
