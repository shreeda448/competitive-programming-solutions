#include "bits/stdc++.h"
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  map<int, int> freq;
  for (int x : a) {
    freq[x]++;
  }
  vector<long long> pref(n, 1);
  vector<long long> dp(n, 1);
  // definition
  // dp[i]=maximum points possible in the range [0....i] ending with index i
  // transition
  // dp[i] = a[i]+ max(dp[j] such that j<i && a[j]<=a[i]-2)
  // base case dp[0]=a[0];
  dp[0] = freq[a[0]] * a[0];
  pref[0] = dp[0];
  for (int i = 1; i < n; i++) {
    dp[i] = (long long)freq[a[i]] * a[i];
    auto it = upper_bound(a.begin(), a.begin() + i, a[i] - 2);
    pref[i] = max(pref[i - 1], dp[i]);
    if (it == a.begin()) {
      continue;
    }
    auto it1 = prev(it);
    int idx = it1 - a.begin();
    dp[i] += pref[idx];
    pref[i] = max(pref[i - 1], dp[i]);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
