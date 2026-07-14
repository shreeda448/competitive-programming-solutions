#include <algorithm>
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
  sort(a.begin(), a.end());
  ll m = a[n - 1];
  ll ans = m * n;
  vector<bool> present(n + 1);
  int current_mex = 0;
  if (a[n - 1] < n) {
    present[a[n - 1]] = true;
    if (a[n - 1] == 0) {
      ans++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < n) {
      present[a[i]] = true;
    }
    while (present[current_mex]) {
      current_mex++;
    }
    ans += current_mex;
  }
  cout << ans << nline;
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
