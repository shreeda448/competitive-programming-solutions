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
const long long INF = 1e18 + 7;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> x(n);
  for (auto &y : x)
    cin >> y;
  ll ans = INF;
  vector<ll> prefix(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix[i] = x[i];
    } else {
      prefix[i] = prefix[i - 1] + x[i];
    }
  }
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      ans = min(ans, 1LL * b * (prefix[n - 1]));
    } else {
      ans = min(ans,
                1LL * (a + b) * x[i - 1] + 1LL * b *
                                               (prefix[n - 1] - prefix[i - 1] -
                                                1LL * (n - i) * x[i - 1]));
    }
  }
  cout << ans << nline;
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
