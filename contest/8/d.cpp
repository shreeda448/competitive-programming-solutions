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
  map<ll, int> freq;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a[i] = x;
    freq[x]++;
  }
  int cnt = 0;
  ll cur = a[0];
  int b = 0;
  vector<int> ind;
  vector<pair<ll, int>> block;
  for (int i = 0; i < n; i++) {
    if (a[i] == cur) {
      cnt++;
    } else {
      // if (freq[cur] == cnt) {
      //
      // } else if (freq[cur] - cnt == 1 || cnt == 1) {
      //   b++;
      // } else {
      //   cout << "NO" << nline;
      //   return;
      // }
      if (freq[cur] != cnt) {
        b++;
        ind.pb(i);
        block.pb({cur, cnt});
      }
      cnt = 1;
      cur = a[i];
    }
    if (i == n - 1) {
      //   if (freq[cur] == cnt) {
      //
      //   } else if (freq[cur] - cnt == 1 || cnt == 1) {
      //     b++;
      //   } else {
      //     cout << "NO" << nline;
      //     return;
      //   }
      if (freq[cur] != cnt) {
        b++;
        ind.pb(i + 1);
        block.pb({cur, cnt});
      }
    }
  }
  b /= 2;
  if (b > 2) {
    cout << "NO" << nline;
    return;
  }
  if (b == 1) {
    if (block[0].second != 1 || block[0].second != freq[block[0].first] - 1) {
      cout << "NO" << nline;
      return;
    }
  }
  cout << "YES" << nline;
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
