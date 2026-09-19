#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve() {
  int n;
  if (!(cin >> n))
    return;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  string ans = "";
  ans += s[0][0];
  vector<pair<int, int>> active;
  active.push_back({0, 0});
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  visited[0][0] = true;
  for (int step = 0; step < 2 * n - 2; ++step) {
    char min_char = 'z' + 1;
    vector<pair<int, int>> next_cells;
    for (auto p : active) {
      int r = p.first;
      int c = p.second;
      if (r + 1 < n)
        min_char = min(min_char, s[r + 1][c]);
      if (c + 1 < n)
        min_char = min(min_char, s[r][c + 1]);
    }
    ans += min_char;
    for (auto p : active) {
      int r = p.first;
      int c = p.second;
      if (r + 1 < n && s[r + 1][c] == min_char && !visited[r + 1][c]) {
        visited[r + 1][c] = true;
        next_cells.push_back({r + 1, c});
      }
      if (c + 1 < n && s[r][c + 1] == min_char && !visited[r][c + 1]) {
        visited[r][c + 1] = true;
        next_cells.push_back({r, c + 1});
      }
    }
    active = next_cells;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
