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

void solve() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  ll ans;
  if (n <= x * z) {
    ans = (n / (x + y));
    if (n % (x + y) != 0)
      ans++;
  } else {
    ll ans1 = (n / (x + y));
    if (n % (x + y) != 0)
      ans1++;
    ll ans2 = (n + 10 * y * z * 1ll) / (x + 10 * y);
    if ((n + 10 * y * z * 1ll) % (x + 10 * y) != 0)
      ans2++;
    ans = min(ans1, ans2);
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
