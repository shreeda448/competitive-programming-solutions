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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> p(n);
  for (auto &x : p)
    cin >> x;
  bool possible = true;
  int g = gcd(x, y);
  for (int i = 0; i < n; i++) {
    if ((p[i]) % g != (i + 1) % g) {
      possible = false;
      break;
    }
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
