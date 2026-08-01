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
  string s;
  cin >> s;
  int n = s.length();
  vector<int> prefix(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    prefix[i] = prefix[i - 1] + (s[i - 2] == s[i - 1] ? 1 : 0);
  }
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l] << "\n";
  }
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
