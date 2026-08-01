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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<pair<int, int>> range(q);
  for (auto &x : range) {
    cin >> x.first >> x.second;
  }
  vector<int> overlap(n + 2);
  for (int i = 0; i < q; i++) {
    overlap[range[i].first]++;
    overlap[range[i].second + 1]--;
  }
  vector<int> freq(n + 2, 0);
  freq[0] = overlap[0];
  for (int i = 1; i < n + 2; i++) {
    freq[i] = freq[i - 1] + overlap[i];
  }
  sort(freq.rbegin(), freq.rend());
  int index = 0;
  sort(a.rbegin(), a.rend());
  ll ans = 0;
  while (index < n && freq[index] != 0) {
    ans += (ll)freq[index] * a[index];
    index++;
  }
  cout << ans << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
