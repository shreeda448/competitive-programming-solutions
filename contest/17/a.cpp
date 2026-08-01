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
  vector<ll> w(n);
  for (auto &x : w) {
    cin >> x;
  }
  if (n & 1) {
    cout << "NO" << nline;
    return;
  }
  long long max_even = -1;
  long long min_odd = 2e9 + 7;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      min_odd = min(min_odd, w[i]);
    } else {
      max_even = max(max_even, w[i]);
    }
  }
  if (min_odd - max_even >= 2) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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
