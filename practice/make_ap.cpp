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
  int a, b, c;
  cin >> a >> b >> c;
  bool possible = false;
  if ((2 * b - c > 0) && (2 * b - c) % a == 0) {
    possible = true;
  } else if ((a + c) % (2 * b) == 0) {
    possible = true;
  } else if ((2 * b - a > 0) && (2 * b - a) % (c) == 0) {
    possible = true;
  }
  if (possible) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
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
