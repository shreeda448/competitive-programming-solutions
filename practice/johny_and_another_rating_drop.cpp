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
  ll n;
  cin >> n;
  ll k = 63;
  // ll low = 0, high = 65;
  // while (low <= high) {
  //   ll mid = low + (high - low) / 2;
  //   ll num = (1 << mid);
  //   ll freq = (n + (num / 2)) / num;
  //   if (freq == 0) {
  //     high = mid - 1;
  //   } else {
  //     k = mid;
  //     low = mid + 1;
  //   }
  //   cout << freq << nline;
  //   // cout << k << nline;
  // }
  ll ans = 0;
  for (int i = 1; i < k; i++) {
    long long cnt = (n + (1LL << (i - 1))) / (1LL << i);
    ans += cnt * i;
  }
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
