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
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  vector<ll> diff(n - 1);
  vector<int> ind;
  ll maxDiff = 0;
  for (int i = 0; i < n - 1; i++) {
    diff[i] = a[i + 1] - a[i];
    if (diff[i] < 0) {
      ind.pb(i);
      maxDiff = max(maxDiff, -diff[i]);
    }
  }
  if (ind.empty()) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < ind.size() - 1; i++) {
    bool found = false;
    for (int j = ind[i] + 1; j < ind[i + 1]; j++) {
      if (diff[j] >= maxDiff) {
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
