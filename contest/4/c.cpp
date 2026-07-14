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
  int n, x, s;
  cin >> n >> x >> s;
  string u;
  cin >> u;
  int ans = n;
  vector<int> g(x);
  int introverts = 0;
  int totalintroverts = 0;
  for (auto b : u) {
    if (b == 'I')
      totalintroverts++;
  }
  int empty = x;
  for (int i = 0; i < n; i++) {
    bool notplaced = true;
    if (u[i] == 'E') {
      for (int j = 0; j < x; j++) {
        if (g[j] > 0 && g[j] < s) {
          g[j]++;
          notplaced = false;
          break;
        }
      }
    } else if (u[i] == 'I') {
      introverts++;
      for (int j = 0; j < x; j++) {
        if (g[j] == 0) {
          g[j]++;
          notplaced = false;
          --empty;
          break;
        }
      }
    } else {
      for (int j = 0; j < x; j++) {
        if (empty > totalintroverts - introverts) {
          if (g[j] == 0) {
            g[j]++;
            notplaced = false;
            --empty;
            break;
          }
        } else {
          if (g[j] > 0 && g[j] < s) {
            g[j]++;
            notplaced = false;
            --empty;
            break;
          }
        }
      }
    }
    if (notplaced) {
      --ans;
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
