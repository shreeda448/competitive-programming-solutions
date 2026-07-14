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

ll ceil(ll x, ll y) {
  if (x % y == 0) {
    return (x / y);
  } else {
    return (x / y) + 1;
  }
}

const int INF = 1e9 + 7;

void solve() {
  ll w, f;
  cin >> w >> f;
  int n;
  cin >> n;
  vector<int> s(n);
  ll total_strength = 0;
  for (auto &x : s) {
    cin >> x;
    total_strength += x;
  }
  bitset<1000005> dp;
  dp[0] = 1;
  for (int x : s) {
    dp |= (dp << x);
  }

  ll ans = INF;
  for (int i = 0; i <= total_strength; i++) {
    if (dp[i]) {
      ans = min({ans,
                 max(ceil(1LL * i, 1LL * w),
                     ceil(1LL * (total_strength - i), 1LL * f)),
                 max(ceil(1LL * i, 1LL * f),
                     ceil(1LL * (total_strength - i), 1LL * w))});
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
