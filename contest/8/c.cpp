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
  int open = 0, close = 0;
  for (char c : s) {
    if (c == '(')
      open++;
    else
      close++;
  }
  int minCost = n + 1;
  int X = 0, Y = 0;
  for (int x = 0; x <= k; x++) {
    int y = k - x;
    if (x > open || y > close) {
      continue;
    }
    vector<bool> deleted(n, false);
    int dOpen = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(' && dOpen < x) {
        deleted[i] = true;
        dOpen++;
      }
    }

    int dClose = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ')' && dClose < y) {
        deleted[i] = true;
        dClose++;
      }
    }
    int curOpen = 0;
    int pairs = 0;
    for (int i = 0; i < n; i++) {
      if (deleted[i])
        continue;
      if (s[i] == '(') {
        curOpen++;
      } else if (s[i] == ')') {
        if (curOpen > 0) {
          pairs++;
          curOpen--;
        }
      }
    }
    if (pairs < minCost) {
      minCost = pairs;
      X = x;
      Y = y;
    }
  }
  string ans(n, '0');
  int dOpen = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(' && dOpen < X) {
      ans[i] = '1';
      dOpen++;
    }
  }
  int dClose = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == ')' && dClose < Y) {
      ans[i] = '1';
      dClose++;
    }
  }
  cout << ans << nline;
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
