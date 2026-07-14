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
  ll x;
  cin >> x;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[l].first + a[r].first == x) {
      cout << a[l].second << " " << a[r].second << nline;
      return;
    } else if (a[l].first + a[r].first < x) {
      l++;
    } else {
      r--;
    }
  }
  cout << "IMPOSSIBLE" << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
