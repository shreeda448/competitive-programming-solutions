#include <algorithm>
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

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n - a - b < 0 || ((max(a, b) > a + b - 1) && (a + b != 0))) {
    cout << "NO\n";
    return;
  }
  int draws = n - a - b;
  int wins = b;
  vector<int> first(n);
  for (int i = 1; i <= n; i++)
    first[i - 1] = i;
  vector<int> second(n);
  for (int i = 1; i <= n; i++) {
    second[i - 1] = i;
  }
  rotate(first.begin() + draws, first.begin() + draws + wins, first.end());
  cout << "YES\n";
  for (auto x : first)
    cout << x << " ";
  cout << "\n";
  for (auto x : second)
    cout << x << " ";
  cout << "\n";
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
