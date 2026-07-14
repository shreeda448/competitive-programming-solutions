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

const int MAX_N = 200001;
ll fact[MAX_N];
const int MOD = 1e9 + 7;

void init() {
  fact[0] = 1;
  for (int i = 1; i < MAX_N; i++)
    fact[i] = fact[i - 1] * i % MOD;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  ll and_of_a = a[0];
  for (int i = 1; i < n; i++) {
    and_of_a &= a[i];
  }
  int cnt = 0;
  for (auto x : a) {
    if (x == and_of_a) {
      cnt++;
    }
  }
  if (cnt < 2) {
    cout << 0 << nline;
    return;
  }
  ll ans = cnt;
  ans %= MOD;
  ans *= (cnt - 1);
  ans %= MOD;
  ans *= fact[n - 2];
  ans %= MOD;
  cout << ans << nline;
}

int main() {
  fastio();
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
