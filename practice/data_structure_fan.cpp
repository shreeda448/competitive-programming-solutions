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
  string s;
  cin >> s;
  ll xor_zero = 0, xor_one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      xor_zero ^= (a[i]);
    } else {
      xor_one ^= (a[i]);
    }
  }
  vector<ll> prefix_xor(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix_xor[i] = a[i];
    } else {
      prefix_xor[i] = (prefix_xor[i - 1] ^ a[i]);
    }
  }

  int q;
  cin >> q;
  for (int query = 0; query < q; query++) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      ll range_xor;
      if (l > 0) {
        range_xor = (prefix_xor[r] ^ prefix_xor[l - 1]);
      } else {
        range_xor = prefix_xor[r];
      }
      xor_one ^= range_xor;
      xor_zero ^= range_xor;
    } else {
      int g;
      cin >> g;
      ll res = (g == 0 ? xor_zero : xor_one);
      cout << res << " ";
    }
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
