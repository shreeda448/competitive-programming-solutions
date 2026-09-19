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

const int MOD = 676767677;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  bool found = false;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != 1) {
      found = true;
      ans += a[i];
      ans %= MOD;
    } else {
      if (found) {
        continue;
      } else {
        found = true;
        ans++;
        ans %= MOD;
      }
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
