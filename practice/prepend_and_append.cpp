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
  int l = 0, r = n - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      break;
    }
    l++;
    r--;
  }
  cout << r - l + 1 << nline;
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
