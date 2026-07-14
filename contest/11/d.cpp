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
  ll or_all = 0;
  for (auto &x : a) {
    cin >> x;
    or_all |= x;
  }
  ll k = 0;
  ll cur_or = 0;
  for (int i = 0; i < n; i++) {
    cur_or |= a[i];
    if (cur_or == or_all) {
      k++;
      cur_or = 0;
    }
  }
  cout << n - k << nline;
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
