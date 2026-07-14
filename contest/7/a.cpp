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
  int n;
  cin >> n;
  vector<ll> b(n);
  for (auto &x : b)
    cin >> x;
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < n - 2; i++) {
    if (b[i + 2] == (b[i] % b[i + 1])) {
      continue;
    } else {
      cout << -1 << nline;
      return;
    }
  }
  cout << b[0] << " " << b[1] << nline;
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
