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

int dfs(int node, int depth, vector<vector<int>> &children, ll &total_guilds) {
  int m1 = depth;
  int m2 = depth;
  for (int child : children[node]) {
    int child_max_depth = dfs(child, depth + 1, children, total_guilds);
    if (child_max_depth > m1) {
      m2 = m1;
      m1 = child_max_depth;
    } else if (child_max_depth > m2) {
      m2 = child_max_depth;
    }
  }
  total_guilds += (m2 - depth);
  return m1;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> children(n + 1);
  for (int i = 2; i <= n; i++) {
    int parent;
    cin >> parent;
    children[parent].push_back(i);
  }
  ll total_guilds = n;
  dfs(1, 0, children, total_guilds);
  cout << total_guilds << nline;
  return;
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
