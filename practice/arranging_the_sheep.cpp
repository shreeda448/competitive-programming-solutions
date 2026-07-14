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
  string s;
  cin >> s;
  vector<int> idx;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      idx.pb(i + 1);
    }
  }
  ll ans = 0;
  ll k = idx.size();
  for (int i = 0; i < k; i++) {
    ans += abs(idx[k / 2] - (k / 2) + i - idx[i]);
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
