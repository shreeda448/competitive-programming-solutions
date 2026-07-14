#include <bits/stdc++.h>
#include <type_traits>
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
  stack<int> stk;
  stk.push(-1);

  int maxLen = 0;
  int cnt = 1;
  int n = s.length();

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      stk.pop();

      if (stk.empty()) {
        stk.push(i);
      } else {
        int len = i - stk.top();

        if (len > maxLen) {
          maxLen = len;
          cnt = 1;
        } else if (len == maxLen) {
          cnt++;
        }
      }
    }
  }

  if (maxLen == 0) {
    cout << 0 << " " << 1 << nline;
  } else {
    cout << maxLen << " " << cnt << nline;
  }
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
