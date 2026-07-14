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
      cin >> grid[n][m];
    }
  }
  int minMoves = 0;
  int maxScore = 0;
  for (int i = 0; i < m; i++) {
    int moves = 0;
    int idx = -1;
    int maxSum = 0;
    int ones = 0;
    for (int j = 0; j < n - k - 1; j++) {
      int sum = 0;
      for (int l = j; l < j + k; l++) {
        sum += grid[l][i];
      }
      if (maxSum < sum) {
        maxSum = sum;
        idx = j;
        moves = ones;
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
