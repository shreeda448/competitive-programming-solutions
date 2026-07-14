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
  vector<vector<int>> prefix_bit(n, vector<int>(33));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 33; j++) {
      if ((a[i] & (1 << j)) == (1 << j)) {
        prefix_bit[i][j]++;
      }
    }
    if (i > 0) {
      for (int j = 0; j < 33; j++) {
        prefix_bit[i][j] += prefix_bit[i - 1][j];
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll l, k;
    cin >> l >> k;
    ll ans = -1;
    ll low = l - 1, high = n - 1;
    while (low <= high) {
      ll mid = low + (high - low) / 2;
      ll num = 0;
      for (int j = 0; j < 33; j++) {
        ll curBitFreq = prefix_bit[mid][j];
        curBitFreq -= (l == 1) ? 0 : prefix_bit[l - 2][j];
        if (curBitFreq == mid - l + 2) {
          num |= (1 << j);
        }
      }
      if (num >= k) {
        ans = max(ans, mid + 1);
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << " ";
  }
  cout << nline;
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
