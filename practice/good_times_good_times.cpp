#include <bits/stdc++.h>
#include <bitset>
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
  ll x;
  cin >> x;
  int d = 0;
  while (x > 0) {
    d++;
    x /= 10;
  }
  ll y = 1;
  for (int i = 0; i < d; i++) {
    y *= 10;
  }
  y++;
  cout << y << nline;
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
