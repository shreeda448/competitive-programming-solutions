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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  if (n == 1) {
    cout << 0 << nline;
    return;
  }
  vector<ll> prefix_max(n);
  prefix_max[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix_max[i] = max(prefix_max[i - 1], a[i]);
  }
  vector<ll> suffix_min(n);
  suffix_min[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix_min[i] = min(suffix_min[i + 1], a[i]);
  }
  int min_pow = -1;
  for (int i = 1; i < n; i++) {
    if (prefix_max[i - 1] > suffix_min[i]) {
      int pow = __builtin_ctz(i);
      min_pow = max(min_pow, pow);
    }
  }
  if (min_pow == -1) {
    cout << 0 << "\n";
    return;
  }
  cout << (1 << min_pow) << "\n";
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
