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
  map<int, ll> mp;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[x - i] += x;
  }
  ll ans = 0;
  for (auto &[key, val] : mp) {
    ans = max(ans, val);
  }
  cout << ans << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
