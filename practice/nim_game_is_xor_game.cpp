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

const int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  if (n == 1) {
    cout << 0 << nline;
    return;
  }
  ll xor_sum = 0;
  for (auto x : a)
    xor_sum ^= x;
  if (xor_sum == 0) {
    cout << 1 << nline;
    return;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] ^ xor_sum) <= a[i]) {
      ans++;
      ans %= MOD;
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
