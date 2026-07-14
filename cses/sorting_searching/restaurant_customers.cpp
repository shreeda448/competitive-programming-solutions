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
  vector<pair<ll, ll>> ab(n);
  for (auto &x : ab) {
    cin >> x.first;
    cin >> x.second;
  }
  map<ll, ll> changes;
  for (int i = 0; i < n; i++) {
    changes[ab[i].first]++;
    changes[ab[i].second]--;
  }
  ll ans = 0;
  ll sum = 0;
  for (auto &[key, val] : changes) {
    sum += val;
    ans = max(ans, sum);
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
