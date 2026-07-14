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
  ll ans = n;
  for (int i = 0; i < n; i++) {
    ll curX = a[i];
    ll L = 0, R = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] < curX) {
        L++;
      }
      if (a[j] > curX) {
        R++;
      }
    }
    ans = min(ans, max(L, R));
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
