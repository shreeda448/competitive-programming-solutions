#include <bits/stdc++.h>
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
  string s;
  cin >> s;
  bool one = false;
  bool zero = false;
  string ans = "";
  for (auto x : s) {
    if (x == '0') {
      if (zero) {
        ans += x;
      } else {
        zero = true;
      }
    } else {
      if (one) {
        ans += x;
      } else {
        one = true;
      }
    }
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
