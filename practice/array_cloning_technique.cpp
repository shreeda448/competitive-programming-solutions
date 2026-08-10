#include <bits/stdc++.h>
#include <cmath>
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
  vector<ll> a(n);
  map<ll, ll> freq;
  for (auto &x : a) {
    cin >> x;
    freq[x]++;
  }

  ll h = a[0];
  bool eq = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != h)
      eq = false;
  }
  if (eq) {
    cout << 0 << nline;
    return;
  }
  ll mx = -1;
  for (auto &[k, v] : freq) {
    mx = max(mx, v);
  }

  ll target = (n + 2 * mx - 1) / (2 * mx);
  ll k = 0;
  while ((1LL << k) < target) {
    k++;
  }
  if (k < 0) {
    cout << 0 << nline;
    return;
  }
  ll p = mx * (1 << (k + 1));
  ll ans = k + 1 + p - mx;
  if (p == n) {
    cout << ans << nline;
    return;
  } else if (p > n) {
    cout << ans - (p - n) << nline;
    return;
  }
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
