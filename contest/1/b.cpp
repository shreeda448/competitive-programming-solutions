
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
  int n, x1, x2, k;
  cin >> n >> x1 >> x2 >> k;
  if (n <= 3) {
    cout << 1 << nline;
  } else {
    cout << k + min(abs(x1 - x2), n - abs(x1 - x2)) << nline;
  }
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
