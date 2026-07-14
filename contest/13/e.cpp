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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      continue;
    } else {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    int ans = ((n + 1) / 2) - 1;
    cout << ans << nline;
    return;
  }
  for (int i = idx + 1; i < n; i++) {
    if (s[i] == 'N') {
      if (s[i - 1] == 'T') {
        s[i] = 'F';
      } else {
        s[i] = 'T';
      }
    }
  }
  for (int i = idx - 1; i >= 0; i--) {
    if (s[i] == 'N') {
      if (s[i + 1] == 'T') {
        s[i] = 'F';
      } else {
        s[i] = 'T';
      }
    }
  }
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'F') {
      cnt++;
    } else {
      if (cnt > 0) {
        ans++;
      }
      cnt = 0;
    }
  }
  if (cnt > 0) {
    ans++;
  }
  cout << ans - 1 << nline;
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
