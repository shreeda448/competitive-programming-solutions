#include <algorithm>
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
  vector<int> a(3);
  for (auto &x : a) {
    cin >> x;
  }
  ll ans = 0;
  while (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) {
    sort(a.begin(), a.end());
    a[0]++;
    a[2]--;
    ans++;
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
