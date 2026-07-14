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

void solve() {
  int n;
  ll M;
  cin >> n >> M;
  vector<int> a(n);

  for (auto &x : a)
    cin >> x;
  vector<ll> prefixON(n);
  vector<ll> prefixOFF(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (i == 0) {
        prefixON[i] = a[i];
        prefixOFF[i] = 0;
      } else {
        prefixON[i] = prefixON[i - 1] + a[i] - a[i - 1];
        prefixOFF[i] = prefixOFF[i - 1];
      }
    } else {
      prefixON[i] = prefixON[i - 1];
      prefixOFF[i] = prefixOFF[i - 1] + a[i] - a[i - 1];
    }
  }
  ll ans = prefixON[n - 1];
  if (n % 2 == 0) {
    ans += M - a[n - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    ll totalONtime = prefixON[i];
    totalONtime += a[i + 1] - a[i] - 1;
    totalONtime += prefixOFF[n - 1] - prefixOFF[i + 1];
    if (n % 2 == 1) {
      totalONtime += M - a[n - 1];
    }
    ans = max(ans, totalONtime);
  }
  ll totalONtime = a[0] - 1 + prefixOFF[n - 1];
  if (n % 2 == 1) {
    totalONtime += M - a[n - 1];
  }
  ans = max(ans, totalONtime);
  totalONtime = prefixON[n - 1];
  if (n % 2 == 1) {
    totalONtime += M - a[n - 1] - 1;
  }
  ans = max(ans, totalONtime);
  cout << ans << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
