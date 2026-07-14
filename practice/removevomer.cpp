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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans;
  string t = "";
  for (int i = 0; i < n; i++) {
    if (t.empty()) {
      t += s[i];
    } else {
      if (s[i] != t.back()) {
        t += s[i];
      }
    }
  }
  int len = t.length();
  if (len >= 3 || len == 1) {
    cout << 1 << nline;
    return;
  }
  cout << 2 << nline;
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
