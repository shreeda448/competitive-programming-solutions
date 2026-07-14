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
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      vector<bool> visited(2 * n + 1, false);
      for (int i = 0; i < row; i++) {
        visited[grid[i][col]] = true;
      }
      for (int i = 0; i < col; i++) {
        visited[grid[row][i]] = true;
      }
      int num = 0;
      while (visited[num]) {
        num++;
      }
      grid[row][col] = num;
      cout << num << " ";
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
