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

vector<int> v[100005];
long long cnt[2];

void dfs(int node, int parent_node, int current_color) {
  cnt[current_color]++;
  for (int sub_node : v[node]) {
    if (sub_node != parent_node) {
      dfs(sub_node, node, 1 - current_color);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, 0, 0);
  cout << cnt[0] * cnt[1] - n + 1 << nline;
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
