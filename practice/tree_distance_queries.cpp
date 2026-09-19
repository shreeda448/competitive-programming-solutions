#include "bits/stdc++.h"
#include <vector>
using namespace std;

void dfs(int parent_node, int current_node, vector<vector<int>> &adj,
         vector<int> &depth, vector<int> &parent) {
  depth[current_node] = depth[parent_node] + 1;
  if (current_node != 1) {
    parent[current_node] = parent_node;
  }
  if (adj[current_node].size() == 1 &&
      adj[current_node].front() == parent_node) {
    return;
  }
  for (int u : adj[current_node]) {
    if (u != parent_node) {
      dfs(current_node, u, adj, depth, parent);
    }
  }
}

int lca(int u, int v, vector<int> &parent, vector<int> &depth) {
  while (depth[u] > depth[v]) {
    u = parent[u];
  }
  while (depth[v] > depth[u]) {
    v = parent[v];
  }
  while (u != v) {
    u = parent[u];
    v = parent[v];
  }
  return u;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> adj(n + 1);
  vector<int> parent(n + 1, -1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> depth(n + 1, 0);
  depth[1] = 0;
  dfs(0, 1, adj, depth, parent);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << depth[u] + depth[v] - 2 * depth[lca(u, v, parent, depth)] << '\n';
  }
}
