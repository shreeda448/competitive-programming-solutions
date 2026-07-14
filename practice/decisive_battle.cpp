#include <bits/stdc++.h>
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
  string s;
  cin >> s;
  int w = 0, e = 0;
  for (char c : s) {
    if (c == 'W') {
      w++;
    } else {
      e++;
    }
  }
  if (w > e) {
    cout << "West" << nline;
    return;
  }
  cout << "East" << nline;
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
