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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n - 1), b(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  a.push_back(1);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll low = 0, high = n;
  ll ans = 1e9 + 7;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    bool valid = true;
    for (int i = 0; i < mid; i++) {
      if (a[i] >= b[i + n - mid]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ans = min(ans, n - mid);
      low = mid + 1;
    } else {
      high = mid - 1;
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
