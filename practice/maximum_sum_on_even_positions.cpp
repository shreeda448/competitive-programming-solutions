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

// observations
// reversing odd length subarray makes no sense
// so reverse even length subarray
// reversing subarray a[l:r] makes sense only if the sum of elements in odd
// indices  is more than the sum of elements in even indices left the diff =
// sum_of_odd_indices- sum_of_even_indices the answer subarray would be the one
// with the maximum value of  diff we pre-compute the prefix odd array and the
// prefix even array iterate through i form 1 to n for length of l:r to be a
// even length subarray r-l+1 should be even if r is even then we need to find
// the minimum prefix odd from 1 to r; if r is odd then we need to find the
// minimum prefix  even from 1 to r; we can pre-compute the prefix odd minimum
// and prefix even minimum too

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ll ans = 0;
  for (int i = 1; i <= n; i += 2) {
    ans += a[i];
  }
  vector<ll> gain1;
  vector<ll> gain2;
  for (int i = 1; i + 1 <= n; i += 2) {
    gain1.push_back(a[i + 1] - a[i]);
  }
  for (int i = 2; i + 1 <= n; i += 2) {
    gain2.push_back(a[i] - a[i + 1]);
  }
  ll current_max_gain1 = 0, global_max_gain1 = LLONG_MIN;
  for (int i = 0; i < gain1.size(); i++) {
    current_max_gain1 = max(gain1[i], current_max_gain1 + gain1[i]);
    global_max_gain1 = max(global_max_gain1, current_max_gain1);
  }
  ll current_max_gain2 = 0, global_max_gain2 = LLONG_MIN;
  for (int i = 0; i < gain2.size(); i++) {
    current_max_gain2 = max(gain2[i], current_max_gain2 + gain2[i]);
    global_max_gain2 = max(global_max_gain2, current_max_gain2);
  }
  cout << ans + max({global_max_gain1, global_max_gain2, 0LL}) << nline;
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
