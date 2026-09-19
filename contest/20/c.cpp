#include <bits/stdc++.h>
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
  ll k;
  cin >> k;
  if (n == 1) {
    if (k == 1) {
      cout << "YES" << nline;
      cout << 0 << nline;
      return;
    } else {
      cout << "NO" << nline;
      return;
    }
  }
  ll num = (ll)n ^ k;
  if (num > 0 && __lg(num) > __lg((ll)(n - 1))) {
    cout << "NO" << nline;
    return;
  }
  vector<ll> s;
  if (num > 0 && num <= n - 1) {
    s.pb(num);
  } else if (num > 0) {
    s.pb(n - 1);
    s.pb((ll)(n - 1) ^ num);
  }
  s.pb(0);
  vector<char> used(n, 0);
  for (ll v : s)
    used[v] = 1;
  vector<ll> a = s;
  for (int i = 0; i < n; i++) {
    if (!used[i])
      a.pb(i);
  }
  cout << "YES" << nline;
  for (int i = (int)a.size() - 1; i >= 0; i--) {
    cout << a[i] << (i == 0 ? nline : " ");
  }
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
