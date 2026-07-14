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
  vector<ll> a(n + 1), cnt(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  vector<ll> have(n + 1);
  have[n] = cnt[n];

  for (ll i = n - 1; i >= 1; i--)
    have[i] = have[i + 1] + cnt[i];

  ll init = 0, aft = 0;
  for (ll i = 1; i <= n; i++) {
    init += i * a[i];
    aft += have[i] * (2 * n - have[i] + 1) / 2;
  }

  ll cur = aft - init, mx = 0;
  for (ll i = 1; i <= n; i++)
    mx = max(mx, i - n + have[a[i]] - 1);

  cout << cur + mx << endl;
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
