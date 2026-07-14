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
  int n;
  cin >> n;
  vector<ll> s(n);
  for (auto &x : s)
    cin >> x;
  ll max_xor = 0;
  stack<ll> stk;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && stk.top() < s[i]) {
      max_xor = max(max_xor, stk.top() ^ s[i]);
      stk.pop();
    }
    if (!stk.empty()) {
      max_xor = max(max_xor, stk.top() ^ s[i]);
    }
    stk.push(s[i]);
  }
  cout << max_xor << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
