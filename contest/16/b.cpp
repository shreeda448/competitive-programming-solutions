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
  long long n, k, m;
  cin >> n >> k >> m;
  if (k > m) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      if (i % k == 0) {
        cout << m - k + 1 << " ";
      } else {
        cout << 1 << " ";
      }
    }
    cout << nline;
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
