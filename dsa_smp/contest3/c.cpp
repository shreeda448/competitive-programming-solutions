#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define nline "\n"

const int INF = 1e9 + 7;

int dfs(int u, const vector<pair<int, int>> &children, const string &s) {
  if (children[u].first == 0 && children[u].second == 0) {
    return 0;
  }
  int min_ops = INF;
  if (children[u].first != 0) {
    int cost = (s[u - 1] == 'L') ? 0 : 1;
    min_ops = min(min_ops, cost + dfs(children[u].first, children, s));
  }
  if (children[u].second != 0) {
    int cost = (s[u - 1] == 'R') ? 0 : 1;
    min_ops = min(min_ops, cost + dfs(children[u].second, children, s));
  }
  return min_ops;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> children(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> children[i].first >> children[i].second;
  }
  cout << dfs(1, children, s) << nline;
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
