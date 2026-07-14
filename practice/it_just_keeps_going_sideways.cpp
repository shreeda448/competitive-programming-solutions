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
  ll sum_of_a = 0;
  for (auto &x : a) {
    cin >> x;
    sum_of_a += x;
  };
  vector<ll> suffix_min(n);
  ll sum_of_suf = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      suffix_min[i] = a[i];
    } else {
      suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }
  }
  for (auto x : suffix_min) {
    sum_of_suf += x;
  }
  int longest_block = 0;
  int len = 0;
  int cur = suffix_min[0];
  for (int i = 0; i < n; i++) {
    if (cur == suffix_min[i]) {
      len++;
    } else {
      longest_block = max(longest_block, len);
      cur = suffix_min[i];
      len = 1;
    }
  }
  if (len > 0) {
    longest_block = max(longest_block, len);
  }
  ll ans = sum_of_a - sum_of_suf + longest_block - 1;
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
