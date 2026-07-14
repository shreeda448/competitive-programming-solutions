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

const int MOD = 998244353;

ll Pow(ll &a, int pow) {
  a %= MOD;
  ll temp = a;
  for (int i = 0; i < pow - 1; i++) {
    temp *= a;
    temp %= MOD;
  }
  return temp;
}

void solve() {
  int n, m;
  cin >> n >> m;
  ll ans = ((n - 1) * (n - 2) * 1LL) / 2;
  ans %= MOD;
  vector<pair<int, int>> ends;
  for (int a = 2; a <= m; a++) {
    for (int b = 2; b <= m; b++) {
      if (gcd(a, b) == 1) {
        ends.push_back({a, b});
      }
    }
  }

  vector<ll> number_of_fillers(ends.size());
  for (int i = 0; i < ends.size(); i++) {
    for (int j = 2; j <= m; j++) {
      if (gcd(ends[i].first, j) > 1 && gcd(ends[i].second, j) > 1) {
        number_of_fillers[i]++;
      }
    }
  }
  int pow = n - 2;
  ll factor = 0;
  for (int i = 0; i < ends.size(); i++) {
    factor += Pow(number_of_fillers[i], pow);
    factor %= MOD;
  }
  ans *= factor;
  ans %= MOD;

  // cout << "ends = " << nline;
  // for (int i = 0; i < ends.size(); i++) {
  //   cout << ends[i].first << " " << ends[i].second << nline;
  // }
  cout << "ans = " << ans << nline;
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
