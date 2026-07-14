#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 1e9;

vector<pair<int, int>> dirs = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                               {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, INF));
  grid[0][0] = 0;
  vector<pair<int, int>> q;
  q.push_back({0, 0});
  for (int i = 0; i < q.size(); i++) {
    auto [row, col] = q[i];
    for (auto dir : dirs) {
      int r1 = row + dir.first;
      int c1 = col + dir.second;
      if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < n && grid[r1][c1] == INF) {
        grid[r1][c1] = grid[row][col] + 1;
        q.push_back({r1, c1});
      }
    }
  }
  for (auto row : grid) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "\n";
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
