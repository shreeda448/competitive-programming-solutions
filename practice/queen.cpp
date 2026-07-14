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

void dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &c,
         vector<bool> &not_possible) {
  if (c[node - 1] == 0) {
    not_possible[node - 1] = true;
    if (parent != -1)
      not_possible[parent - 1] = true;
  }
  for (auto ch : adj[node]) {
    if (ch != parent) {
      dfs(ch, adj, node, c, not_possible);
    }
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> parent(n);
  vector<int> c(n);
  vector<vector<int>> adj(n + 1);
  vector<bool> not_possible(n + 1, false);
  int root_node;
  for (int i = 1; i <= n; i++) {
    cin >> parent[i - 1];
    cin >> c[i - 1];
    if (parent[i - 1] == -1) {
      root_node = i;
    }
    if (parent[i - 1] != -1)
      adj[parent[i - 1]].push_back(i);
    adj[i].push_back(parent[i - 1]);
  }
  dfs(root_node, adj, -1, c, not_possible);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!not_possible[i]) {
      cout << i + 1 << " ";
      cnt++;
    }
  }
  if (!cnt) {
    cout << -1;
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
