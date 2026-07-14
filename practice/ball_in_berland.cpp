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
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> boy(k);
  vector<int> girl(k);
  for (auto &x : boy)
    cin >> x;
  for (auto &x : girl)
    cin >> x;
  vector<int> freq_boy(a + 1);
  vector<int> freq_girl(b + 1);
  for (int i = 0; i < k; i++) {
    freq_boy[boy[i]]++;
  }
  for (int i = 0; i < k; i++) {
    freq_girl[girl[i]]++;
  }
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    ans += 1LL * (k - freq_boy[boy[i]] - freq_girl[girl[i]] + 1);
  }
  ans /= 2;
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
