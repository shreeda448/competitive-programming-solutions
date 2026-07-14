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
  if (n == 2) {
    cout << -1 << nline;
    return;
  }
  if (n == 1) {
    cout << 1 << nline;
    return;
  }
  vector<ll> res = {1, 2, 3};
  ll current_sum = 6;
  while ((int)res.size() < n) {
    res.pb(current_sum);
    current_sum *= 2;
  }
  for (auto x : res) {
    cout << x << " ";
  }
  cout << nline;
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
