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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> bits(22, 0);
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    for (int bit = 0; bit < 22; bit++) {
      int num = (1 << bit);
      if ((num & a[i]) == num) {
        bits[bit]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ll cur_el = 0;
    for (int j = 21; j >= 0; --j) {
      if (bits[j] > 0) {
        cur_el += (1 << j);
        bits[j]--;
      }
    }
    b[i] = cur_el;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (b[i] * b[i]);
  }
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
