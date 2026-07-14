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
  vector<pair<ll, ll>> times(n);
  for (auto &x : times) {
    cin >> x.second;
    cin >> x.first;
  }
  sort(times.begin(), times.end());
  ll ans = 0;
  ll lastTime = times[0].first;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans++;
      lastTime = max(lastTime, times[i].first);
    } else {
      if (times[i].second >= lastTime) {
        ans++;
        lastTime = max(lastTime, times[i].first);
      }
    }
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
