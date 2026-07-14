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
  int n = s.length();
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      for (char c = 'a'; c <= 'c'; c++) {
        if (c != s[i - 1] && (i == n - 1 || c != s[i + 1])) {
          s[i] = c;
          break;
        }
      }
    }
  }
  cout << s << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
