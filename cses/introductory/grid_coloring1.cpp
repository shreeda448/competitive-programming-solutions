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
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &x : grid)
    cin >> x;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      vector<bool> letters(4, false);
      if (row > 0) {
        letters[grid[row - 1][col] - 'A'] = true;
      }
      if (col > 0) {
        letters[grid[row][col - 1] - 'A'] = true;
      }
      int idx = 0;
      while (letters[idx] || grid[row][col] == 'A' + idx) {
        idx++;
      }
      grid[row][col] = 'A' + idx;
    }
  }
  for (auto row : grid) {
    cout << row << "\n";
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
