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
  ll n;
  cin >> n;
  if (n < 8) {
    cout << "NO" << nline;
    return;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
          if (j != (i / j) && (n / i) != j && (n / i) != (i / j)) {
            cout << "YES" << nline;
            cout << j << " " << (n / i) << " " << (i / j) << nline;
            return;
          }
        }
      }

      for (int j = 2; j * j <= (n / i); j++) {
        if ((n / i) % j == 0) {
          if (j != ((n / i) / j) && (i) != j && (i) != ((n / i) / j)) {
            cout << "YES" << nline;
            cout << j << " " << (i) << " " << ((n / i) / j) << nline;
            return;
          }
        }
      }
    }
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
