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
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  // converting odd nuumbers to even
  // also counting  number of zero unit digits
  int zeroes = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      a[i] += (a[i] % 10);
    }
    if (a[i] % 10 == 0) {
      zeroes++;
    }
  }
  if (zeroes > 0 && zeroes < n) {
    cout << "NO" << nline;
    return;
  }
  if (zeroes == n) {
    ll cur = a[0];
    for (int i = 0; i < n; i++) {
      if (a[i] != cur) {
        cout << "NO" << nline;
        return;
      }
    }
    cout << "YES" << nline;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 10 == 4) {
      a[i] += 18;
    } else if (a[i] % 10 == 6) {
      a[i] += 6;
    } else if (a[i] % 10 == 8) {
      a[i] += 14;
    }
  }
  int rem = a[0] % 20;
  for (int i = 0; i < n; i++) {
    if (a[i] % 20 != rem) {
      cout << "NO" << nline;
      return;
    }
  }
  cout << "YES" << nline;
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
