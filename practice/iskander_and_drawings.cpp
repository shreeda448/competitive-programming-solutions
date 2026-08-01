#include <algorithm>
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
  int max_line = 0;
  int line = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      line++;
    } else {
      max_line = max(max_line, line);
      line = 0;
    }
  }
  if (line > 0) {
    max_line = max(max_line, line);
  }
  cout << (max_line + 1) / 2 << nline;
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
