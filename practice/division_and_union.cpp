#include <algorithm>
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
  vector<vector<int>> p(n);
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    p[i] = {l, r, i};
  }
  sort(p.begin(), p.end());
  vector<int> ans(n, 2);
  int mx = p[0][1];
  bool split_found = false;
  for (int i = 0; i < n; i++) {
    if (p[i][0] <= mx) {
      ans[p[i][2]] = 1;
      mx = max(mx, p[i][1]);
    } else {
      split_found = true;
      break;
    }
  }
  if (!split_found) {
    cout << -1 << nline;
    return;
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << nline;
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
