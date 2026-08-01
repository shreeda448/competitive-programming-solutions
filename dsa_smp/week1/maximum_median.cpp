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

void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  long long low = a[n / 2];
  long long ans = low;
  long long high = a[n - 1] + k;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long ops = 0;
    for (int i = n / 2; i < n; i++) {
      if (a[i] < mid) {
        ops += mid - a[i];
      }
    }
    if (ops <= k) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
