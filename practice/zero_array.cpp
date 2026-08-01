#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
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
  ll sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  if (sum % 2 == 1) {
    cout << "NO" << nline;
    return;
  }
  ll mx = *max_element(a.begin(), a.end());
  if (sum >= 2 * mx) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
