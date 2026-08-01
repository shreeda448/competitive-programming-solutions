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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  if (n < 2 * m) {
    cout << "NO" << nline;
    return;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  bool possible = true;
  for (int i = 0; i < m; i++) {
    if (a[i] < b[i] && a[n - m + i] > b[i]) {
      continue;
    } else {
      possible = false;
      break;
    }
  }
  if (possible) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
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
