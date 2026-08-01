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
  vector<ll> x(n);
  vector<ll> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  ll part1 = (x[n / 2] - x[(n - 1) / 2]) + 1;
  ll part2 = (y[n / 2] - y[(n - 1) / 2]) + 1;
  cout << part1 * part2 << nline;
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
