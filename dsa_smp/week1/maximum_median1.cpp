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
  long long sum = 0;
  for (int i = n / 2; i < n; i++) {
    sum += a[i];
  }
  long long ans = k + sum;
  ans /= n - (n / 2);
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
