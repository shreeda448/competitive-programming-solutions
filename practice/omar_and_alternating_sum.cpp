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

const int MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  int number_of_neg_ones = 0;
  set<ll> uniq;
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      number_of_neg_ones++;
    }
    if (uniq.count(a[i])) {
      continue;
    }
    uniq.insert(a[i]);
  }
  int d = uniq.size();
  if (number_of_neg_ones == 0) {
    cout << binpow(2, n - d, MOD) << nline;
    return;
  }
  ll ans = binpow(2, n - d, MOD);
  int l = 0;
  for (auto x : uniq) {
    if (uniq.count(x + 1)) {
      l++;
    }
  }
  ans *= (l + 1);
  ans %= MOD;
  cout << ans << nline;
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
