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

int paint(string s, vector<int> &color) {
  int n = s.length();
  int open = 0, close = 0;
  for (char c : s) {
    if (c == '(') {
      open++;
    } else {
      close++;
    }
  }
  if (open != close) {
    return -1;
  }
  stack<int> stk;
  int color1 = 0, color2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      if (!stk.empty()) {
        color[stk.top()] = 1;
        color[i] = 1;
        color1++;
        stk.pop();
      } else {
        color[i] = 2;
        color2++;
      }
    }
  }
  while (!stk.empty()) {
    color[stk.top()] = 2;
    color2++;
    stk.pop();
  }
  int k = 0;
  if (color1 == 0) {
    for (int i = 0; i < n; i++) {
      color[i] = 1;
    }
  } else {
    k++;
  }
  if (color2 > 0)
    k++;
  return k;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> color_normal(n);
  vector<int> color_reverse(n);
  int ans1 = paint(s, color_normal);
  reverse(s.begin(), s.end());
  int ans2 = paint(s, color_reverse);
  if (ans1 <= ans2) {
    cout << ans1 << nline;
    if (ans1 != -1) {
      for (int color : color_normal) {
        cout << color << " ";
      }
    }
  } else {
    cout << ans2 << nline;
    reverse(color_reverse.begin(), color_reverse.end());
    for (int color : color_reverse) {
      cout << color << " ";
    }
  }
  cout << nline;
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
