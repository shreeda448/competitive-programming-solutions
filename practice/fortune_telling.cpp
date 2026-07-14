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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (auto &p : a)
    cin >> p;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (y % 2 == 0) {
    if (sum % 2 == 0) {
      if (x % 2 == 0) {
        cout << "Alice" << nline;
      } else {
        cout << "Bob" << nline;
      }
    } else {
      if (x % 2 == 1) {
        cout << "Alice" << nline;
      } else {
        cout << "Bob" << nline;
      }
    }
  } else {
    if (sum % 2 == 0) {
      if (x % 2 == 0) {
        cout << "Bob" << nline;
      } else {
        cout << "Alice" << nline;
      }
    } else {
      if (x % 2 == 1) {
        cout << "Bob" << nline;
      } else {
        cout << "Alice" << nline;
      }
    }
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
