#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define nline "\n"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  vector<ll> pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  ll ans = 0;
  int last = 0;
  for (int i = 0; i < m; i++) {
    ans += abs(pref[b[i]] - pref[last]);
    last = b[i];
  }
  ans += (pref[n] - pref[last]);
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
