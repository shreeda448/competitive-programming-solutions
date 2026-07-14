#include <bits/stdc++.h>
#include <climits>
#include <iterator>
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
  ll k;
  cin >> k;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  if (k > 2) {
    cout << 0 << nline;
    return;
  }
  sort(a.begin(), a.end());
  ll ans = a[0];
  for (int i = 0; i < n - 1; i++) {
    ans = min({ans, abs(a[i] - a[i + 1])});
  }
  if (k == 1) {
    cout << ans << nline;
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      ll v = a[i] - a[j];
      auto p = lower_bound(a.begin(), a.end(), v);
      int g = distance(a.begin(), p);
      if (g < n)
        ans = min(ans, a[g] - v);
      if (g > 0)
        ans = min(ans, v - a[g - 1]);
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
