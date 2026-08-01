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
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  a[1] += a[0] - 1;
  a[0] = 1;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] - a[i - 1] - 1 < 0) {
      cout << "NO" << nline;
      return;
    }
    a[i + 1] += a[i] - a[i - 1] - 1;
    a[i] = a[i - 1] + 1;
  }
  bool possible = true;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] <= a[i]) {
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
