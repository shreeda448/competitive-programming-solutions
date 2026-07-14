#include <bits/stdc++.h>
#include <string>
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
  ll n;
  cin >> n;
  int rem = n % 12;
  int p[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};
  if (p[rem] > n) {
    cout << -1 << nline;
    return;
  }
  cout << p[rem] << " " << n - p[rem] << nline;
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
