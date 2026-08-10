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

void solve() {
  string s;
  cin >> s;
  ll cnt = 0;
  ll p = 1;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'a') {
      cnt++;
    } else if (s[i] == 'b') {
      p = p * (cnt + 1) % MOD;
      cnt = 0;
    }
  }
  p = p * (cnt + 1) % MOD;
  ll ans = (p - 1 + MOD) % MOD;
  cout << ans << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
