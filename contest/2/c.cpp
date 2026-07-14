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

void solve() {
  int n;
  cin >> n;
  vector<ll> c(n);
  ll sum = 0;
  ll cnt = 0;
  ll cnt2 = 0;
  for (auto &x : c) {

    cin >> x;
    sum += x;
    if (x > 3) {
      cnt += (x / 2) - 1;
    }
    if (x > 1) {
      cnt2++;
    }
  }
  if (cnt2 == 1)
    cnt++;
  if (sum < 3) {
    cout << 0 << "\n";
    return;
  }
  ll ans = 0;
  bool one = true;
  ll cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == 1 && one) {
      cnt1++;
      if (cnt1 == cnt) {
        ans++;
        one = false;
      } else if (cnt1 < cnt) {
        ans++;
      } else {
        one = false;
      }
    }
    if (c[i] > 1) {
      ans += c[i];
    }
  }
  if (ans < 3) {
    cout << 0 << "\n";
    return;
  }
  cout << ans << "\n";
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
