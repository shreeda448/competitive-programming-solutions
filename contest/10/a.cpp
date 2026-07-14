#include <bits/stdc++.h>
#include <queue>
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  queue<pair<int, int>> children;
  for (int i = 1; i <= n; i++) {
    children.push(a[i - 1]);
  }
  int lastChild;
  while (!children.empty()) {
    pair<int, int> cur = children.front();
    lastChild = cur.second;
    children.pop();
    if (cur.first > m) {
      children.push({cur.first - m, cur.second});
    }
  }
  cout << lastChild << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
