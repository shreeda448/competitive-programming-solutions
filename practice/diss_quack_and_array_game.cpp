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

const int INF = 1e9 + 7;

ll func(int a) {
  int temp = a;
  int log = 0;
  for (int i = 0; i < 20; i++) {
    if (temp == 0) {
      break;
    }
    if (temp % 2 == 1) {
      log = i;
    }
    temp /= 2;
  }
  int pop_count = __builtin_popcount(a);
  ll res = pop_count + log;
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  int gcd_a{a[0]};
  for (auto x : a) {
    gcd_a = gcd(gcd_a, x);
  }
  ll ans = INF;
  int log = 0;
  while ((gcd_a & 1) == 0) {
    log++;
    gcd_a >>= 1;
  }
  for (int g = log; g <= 20; g++) {
    ll res = g;
    for (int i = 0; i < n; i++) {
      long long best = INF;
      int p = 1 << g;
      int first = ((a[i] + p - 1) / p) * p;
      for (int b = first; b <= first + 32; b += p) {
        best = min(best, 1LL * (b - a[i]) + func(b / p));
      }
      res += best;
    }
    ans = min(ans, res);
  }
  cout << ans << nline;
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
