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
  int m, n;
  cin >> m >> n;
  vector<vector<ll>> p(m, vector<ll>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  ll low = 1, high = 1e9;
  ll ans = 1;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    bool possible = false;
    bool all_happy = true;
    vector<vector<int>> temp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (p[i][j] >= mid) {
          temp[i][j] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        cnt += temp[j][i];
      }
      if (cnt == 0) {
        all_happy = false;
        break;
      }
    }
    if (all_happy) {

      for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          cnt += temp[i][j];
        }
        if (cnt >= 2) {
          possible = true;
          break;
        }
      }
    }
    if (possible) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << nline;
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
