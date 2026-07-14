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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  map<ll, int> freq;
  for (auto x : a) {
    if (x % k == 0) {
      continue;
    }
    freq[x % k]++;
  }
  ll ans = 0;
  for (auto &[key, val] : freq) {
    ans = max(ans, val * k - key);
  }
  if (ans > 0) {
    ans++;
  }
  cout << ans << nline;
  return;
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
