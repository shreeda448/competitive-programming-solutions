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

vector<pair<int, int>> moves;

void shift(int n, int start, int end) {
  if (n == 1) {
    moves.pb({start, end});
    return;
  } else {
    shift(n - 1, start, 6 - start - end);
    moves.pb({start, end});
    shift(n - 1, 6 - start - end, end);
  }
}

void solve() {
  int n;
  cin >> n;
  shift(n, 1, 3);
  cout << moves.size() << "\n";
  for (auto x : moves) {
    cout << x.first << " " << x.second << "\n";
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
