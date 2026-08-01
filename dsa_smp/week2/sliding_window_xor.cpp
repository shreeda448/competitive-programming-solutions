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
  int n, k;
  ll x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;
  vector<ll> nums(n);
  nums[0] = x;
  for (int i = 1; i < n; i++) {
    nums[i] = (a * nums[i - 1] + b) % c;
  }
  vector<ll> prefix(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix[i] = nums[i];
    } else {
      prefix[i] = prefix[i - 1] ^ nums[i];
    }
  }
  ll ans;
  for (int i = k - 1; i < n; i++) {
    if (i == k - 1) {
      ans = prefix[i];
    } else {
      ans ^= prefix[i] ^ prefix[i - k];
    }
  }
  cout << ans << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
