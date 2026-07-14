#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> fr(n + 1, 0);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    fr[a[i]]++;
  }
  ll low = 0, high = 2 * m;
  ll ans = INF;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += min(mid, fr[i] + (mid - fr[i]) / 2);
    }
    if (sum >= m) {
      ans = min(ans, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
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
