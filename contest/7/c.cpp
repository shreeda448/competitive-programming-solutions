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
  vector<ll> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<ll> ans(n);
  for (int i = 0; i < n; i++) {
    vector<ll> line(n);
    for (int j = 0; j < n; j++) {
      line[j] = h[(i + j) % n];
    }
    vector<ll> preMax(n);
    preMax[0] = line[0];
    for (int i = 1; i < n; ++i) {
      preMax[i] = max(preMax[i - 1], line[i]);
    }
    vector<long long> suffMax(n);
    suffMax[n - 1] = line[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      suffMax[i] = max(suffMax[i + 1], line[i]);
    }
    ll totalWater = 0;
    for (int i = 1; i < n; ++i) {
      totalWater += min(preMax[i - 1], suffMax[i]);
    }
    ans[i] = totalWater;
  }
  for (int k = 0; k < n; ++k) {
    cout << ans[k] << (k == n - 1 ? "" : " ");
  }
  cout << nline;
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
