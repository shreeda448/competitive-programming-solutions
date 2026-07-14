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
  int n, m;
  cin >> m >> n;
  if (m - n >= 0) {
    cout << m - n << nline;
    return;
  }
  if ((n - m) % 2 == 0) {
    cout << 0 << nline;
    return;
  }
  cout << 1 << nline;
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
