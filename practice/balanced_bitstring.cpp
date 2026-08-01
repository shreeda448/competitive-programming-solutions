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
  cin >> n >> k;
  string s;
  cin >> s;
  bool possible = true;
  vector<char> grp(k, '?');
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (grp[i % k] != '?') {
        s[i] = grp[i % k];
      }
    } else {
      if (grp[i % k] == '?') {
        grp[i % k] = s[i];
      } else if (grp[i % k] != s[i]) {
        possible = false;
        break;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    s[i] = grp[i];
  }
  int ones = 0, zeroes = 0, q = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '0') {
      zeroes++;
    } else if (s[i] == '1') {
      ones++;
    } else {
      q++;
    }
  }
  if (abs(ones - zeroes) > q) {
    possible = false;
  } else {
    if ((q - abs(ones - zeroes)) % 2 == 1) {
      possible = false;
    }
  }
  if (possible) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
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
