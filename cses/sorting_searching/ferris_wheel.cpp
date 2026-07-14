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
  ll x;
  cin >> n >> x;
  vector<ll> p(n);
  for (auto &x : p)
    cin >> x;
  int l = 0, r = n - 1;
  sort(p.begin(), p.end());
  ll ans = 0;
  while (l < r) {
    if (p[l] + p[r] <= x) {
      l++;
    }
    ans++;
    --r;
  }
  if (l == r) {
    ans++;
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
