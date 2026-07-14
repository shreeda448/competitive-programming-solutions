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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> freq(n + 1, 0);
  for (int i = 0; i < n; i++) {
    freq[a[i]]++;
  }
  sort(freq.rbegin(), freq.rend());
  int idx = 0, num = freq[0] + 1;
  ll ans = 0;
  while (idx < n && num > 0) {
    if (freq[idx] >= num) {
      ans += num - 1;
      num--;
    } else {
      ans += freq[idx];
      num = freq[idx];
    }
    idx++;
  }
  cout << ans << nline;
  return;
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
