#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long

const int MAXC = 100005;
vector<int> rows[MAXC];
vector<int> cols[MAXC];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      rows[c].push_back(i);
      cols[c].push_back(j);
    }
  }

  ll ans = 0;
  for (int c = 1; c < MAXC; c++) {
    if (rows[c].empty())
      continue;

    ll k = rows[c].size();
    sort(rows[c].begin(), rows[c].end());
    for (ll i = 0; i < k; i++) {
      ans += 1LL * rows[c][i] * i;
      ans -= 1LL * rows[c][i] * (k - 1 - i);
    }
    sort(cols[c].begin(), cols[c].end());
    for (ll i = 0; i < k; i++) {
      ans += 1LL * cols[c][i] * i;
      ans -= 1LL * cols[c][i] * (k - 1 - i);
    }
  }

  cout << ans << "\n";
}

int main() {
  fastio();
  int t = 1;
  // cin >> t; // Only 1 testcase per run in this problem
  while (t--) {
    solve();
  }
  return 0;
}
