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
  vector<ll> b(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  bool possible = true;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= b[i]) {
      continue;
    }
    if (i > 0) {
      a[i - 1] += a[i] - b[i];
    } else {
      possible = false;
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
