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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < 2 * a[i + 1]) {
      if (cnt + 1 >= k) {
        ans++;
      }
      cnt++;
    } else {
      cnt = 0;
    }
  }
  // if (cnt >= k) {
  //   ans++;
  // }
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
