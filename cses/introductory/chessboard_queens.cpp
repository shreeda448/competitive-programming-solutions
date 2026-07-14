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

long long perms = 0;

void placeQueen(vector<vector<char>> &board, int row) {
  if (row == 8) {
    perms++;
    return;
  }
  for (int col = 0; col < 8; col++) {
    if (board[row][col] == '.') {
      bool attacked = false;
      for (int r = row - 1; r >= 0; --r) {
        if (board[r][col] == 'Q') {
          attacked = true;
        }
      }
      for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c) {
        if (board[r][c] == 'Q') {
          attacked = true;
        }
      }
      for (int r = row - 1, c = col + 1; r >= 0 && c < 8; --r, ++c) {
        if (board[r][c] == 'Q') {
          attacked = true;
        }
      }
      if (!attacked) {
        board[row][col] = 'Q';
        placeQueen(board, row + 1);
        board[row][col] = '.';
      }
    }
  }
}

void solve() {
  vector<vector<char>> board(8, vector<char>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> board[i][j];
    }
  }
  placeQueen(board, 0);
  cout << perms << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
