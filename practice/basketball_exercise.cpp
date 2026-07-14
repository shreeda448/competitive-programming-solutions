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
  vector<ll> h1(n);
  vector<ll> h2(n);
  for (auto &x : h1)
    cin >> x;
  for (auto &x : h2)
    cin >> x;
  vector<ll> dp1(n);
  vector<ll> dp2(n);
  dp1[0] = h1[0];
  dp2[0] = h2[0];
  for (int i = 1; i < n; i++) {
    dp1[i] = max({dp1[i], dp2[i - 1] + h1[i], dp1[i - 1]});
    dp2[i] = max({dp2[i], dp1[i - 1] + h2[i], dp2[i - 1]});
  }
  cout << max(dp1[n - 1], dp2[n - 1]) << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
