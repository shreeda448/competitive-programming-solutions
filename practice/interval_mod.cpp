#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k, p, q, a[100009], f[100009][2], g[100009];
inline ll read() {
  ll s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
int main() {
  t = read();
  while (t--) {
    ll ans = 1e18;
    n = read(), k = read(), p = read(), q = read();
    for (ll i = 1; i <= n; i += 1)
      a[i] = read();
    for (ll i = 1; i <= n; i += 1)
      f[i][0] = a[i] % p % q, f[i][1] = a[i] % q % p;
    for (ll i = 1; i <= n; i += 1)
      g[i] = g[i - 1] + min(f[i][0], f[i][1]);
    for (ll i = 1; i <= n; i += 1)
      f[i][0] += f[i - 1][0], f[i][1] += f[i - 1][1];
    for (ll i = k; i <= n; i += 1)
      ans = min(ans, min(f[i][0] - f[i - k][0], f[i][1] - f[i - k][1]) +
                         g[i - k] + g[n] - g[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
