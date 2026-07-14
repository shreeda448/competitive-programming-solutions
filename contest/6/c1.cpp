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
#define nline "\n"

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int minMoves = 0;
  int maxScore = 0;

  for (int i = 0; i < m; i++) {
    int moves = 1e9;
    int maxSum = -1;
    int ones = 0;
    for (int j = 0; j < n; j++) {
      int sum = 0;

      for (int l = j; l < min(n, j + k); l++) {
        sum += grid[l][i];
      }

      if (sum > maxSum) {
        maxSum = sum;
        moves = ones;
      } else if (sum == maxSum) {
        moves = min(moves, ones);
      }

      ones += grid[j][i];
    }

    maxScore += maxSum;
    minMoves += moves;
  }

  cout << maxScore << " " << minMoves << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
