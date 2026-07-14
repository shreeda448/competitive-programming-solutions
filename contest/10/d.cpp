#include <bits/stdc++.h>
#include <unistd.h>
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
  int n = s.length();
  vector<char> min_remain(n);
  min_remain[n - 1] = s[n - 1];

  for (int i = n - 2; i >= 0; --i) {
    min_remain[i] = min(s[i], min_remain[i + 1]);
  }
  stack<char> t;
  string u = "";

  for (int i = 0; i < n; ++i) {
    t.push(s[i]);
    while (!t.empty()) {
      if (i + 1 < n && min_remain[i + 1] < t.top()) {
        break;
      }
      u += t.top();
      t.pop();
    }
  }
  cout << u << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
