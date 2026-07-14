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
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  for (int x = 1; x <= n; x++) {
    ll ans = 0;
    vector<ll> prefixMin(n);
    vector<ll> suffixMin(n);
    for (int i = 0; i < n; i++) {
      if (i % x == 0) {
        prefixMin[i] = a[i];
      } else {
        prefixMin[i] = min(prefixMin[i - 1], a[i]);
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (i == n - 1 || i % x == 0) {
        suffixMin[i] = a[i];
      } else {
        suffixMin[i] = min(a[i], suffixMin[i + 1]);
      }
    }
    for (int i = 0; i <= n - x; i++) {
      int l = i, r = i + x - 1;
      ll m = min(suffixMin[l], prefixMin[r]);
      ans = max(ans, m);
    }
    cout << ans << " ";
  }
  cout << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
