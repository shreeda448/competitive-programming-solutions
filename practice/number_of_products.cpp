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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  vector<ll> prefix_neg(n);
  vector<ll> prefix_odd(n);
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      prefix_neg[i] = (a[i] < 0 ? 1 : 0);
    } else {
      prefix_neg[i] = prefix_neg[i - 1] + (a[i] < 0 ? 1 : 0);
    }
  }
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      prefix_odd[i] = ((prefix_neg[i] & 1) ? 1 : 0);
    } else {
      prefix_odd[i] = prefix_odd[i - 1] + ((prefix_neg[i] & 1) ? 1 : 0);
    }
  }
  ll ans_neg = prefix_neg[0];
  for (ll i = 1; i < n; i++) {
    if (prefix_neg[i] % 2 == 1) {
      ans_neg += (i - prefix_odd[i - 1] + 1);
    } else {
      ans_neg += (prefix_odd[i - 1]);
    }
  }
  ll ans_pos = (n + 1) * n * 1LL / 2;
  ans_pos -= ans_neg;
  cout << ans_neg << " " << ans_pos << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
