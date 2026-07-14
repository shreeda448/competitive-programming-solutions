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
  int n, k;
  ll m;
  cin >> n >> m >> k;
  vector<ll> b(n);
  for (auto &x : b)
    cin >> x;
  ll max_len = b.back() - b.front() + 1;
  vector<ll> diff(n - 1);
  for (int i = 0; i < n - 1; i++) {
    diff[i] = b[i + 1] - b[i] - 1;
  }
  sort(diff.rbegin(), diff.rend());
  ll first_k = 0;
  for (int i = 0; i < k - 1; i++) {
    first_k += diff[i];
  }
  ll ans = max_len - first_k;
  cout << ans << nline;
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
