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
  ll sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  vector<ll> prefix(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix[i] = a[i];
    } else {
      prefix[i] = prefix[i - 1] + a[i];
    }
  }
  vector<ll> prefix_min(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix_min[i] = prefix[i];
    } else {
      prefix_min[i] = min(prefix_min[i - 1], prefix[i]);
    }
  }
  ll m = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      m = max(m, prefix[i]);
    } else if (i < n - 1) {
      m = max(m, prefix[i] - min(prefix_min[i - 1], 0LL));
    } else if (i == n - 1) {
      m = max(m, prefix[i] - prefix_min[i - 1]);
    }
  }
  if (m >= sum) {
    cout << "NO" << nline;
    return;
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
