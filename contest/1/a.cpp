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
  vector<int> w(n);
  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    if (w[i] % 3 == 0) {
      cnt3++;
    } else if (w[i] % 3 == 1) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  ll ans = 0;
  ans += cnt3;
  ans += min(cnt2, cnt1);
  ans += (max(cnt2, cnt1) - min(cnt1, cnt2)) / 3;
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
