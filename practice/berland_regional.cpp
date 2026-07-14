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
  vector<int> u(n);
  set<int> un;
  vector<ll> power(n);
  vector<vector<ll>> university(n + 1);
  for (auto &x : u) {
    cin >> x;
    un.insert(x);
  }
  for (auto &x : power) {
    cin >> x;
  }
  for (int i = 0; i < n; i++) {
    university[u[i]].push_back(power[i]);
  }
  for (auto uni : un) {
    sort(university[uni].rbegin(), university[uni].rend());
  }
  vector<vector<ll>> prefix(n + 1);
  vector<ll> res(n + 1);
  for (auto x : un) {
    int num_prog = university[x].size();
    prefix[x].pb(0);
    for (int i = 0; i < num_prog; i++) {
      prefix[x].pb(university[x][i] + prefix[x].back());
    }
  }
  for (int i = 1; i <= n; i++) {
    int s = university[i].size();
    for (int k = 1; k <= s; k++) {
      res[k] += (prefix[i][(s / k) * k]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
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
