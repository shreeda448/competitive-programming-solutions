#include <bits/stdc++.h>
using namespace std;

// recursion / backtracking

const int N = 7;
const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const string moves = "UDRL";
long long answer;
bool visited[N][N];
string input;

const vector<pair<int, int>> eight_dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                                           {1, 1},   {1, 0},  {1, -1}, {0, -1}};

bool isInside(int row, int col) {
  return 0 <= min(row, col) && max(row, col) < N;
}
bool isEmpty(int row, int col) {
  return isInside(row, col) && !visited[row][col];
}

void dfs(int row, int col, int i) {
  // if (row == N - 1 && col == 0 && i != N * N - 1) {
  // return;
  // }

  // checkerboard pattern
  if (row >= 1 && col >= 1 && isEmpty(row - 1, col) && isEmpty(row, col - 1) &&
      !isEmpty(row - 1, col - 1)) {
    return;
  }
  if (row >= 1 && col <= N - 2 && isEmpty(row - 1, col) &&
      isEmpty(row, col + 1) && !isEmpty(row - 1, col + 1)) {
    return;
  }
  if (row <= N - 2 && col >= 1 && isEmpty(row + 1, col) &&
      isEmpty(row, col - 1) && !isEmpty(row + 1, col - 1)) {
    return;
  }
  if (row <= N - 2 && col <= N - 2 && isEmpty(row + 1, col) &&
      isEmpty(row, col + 1) && !isEmpty(row + 1, col + 1)) {
    return;
  }

  // check of cross-pattern: empty cell above&below or left&right from you
  if (isEmpty(row - 1, col) && isEmpty(row + 1, col) &&
      !isEmpty(row, col - 1) && !isEmpty(row, col + 1)) {
    return;
  }
  if (!isEmpty(row - 1, col) && !isEmpty(row + 1, col) &&
      isEmpty(row, col - 1) && isEmpty(row, col + 1)) {
    return;
  }

  /*
  // among your 8 neighbours, check if empty cells form <= 1 CC
  bool eight[8];
  int nxt = 0;
  for (const pair<int,int>& dir : eight_dirs) {
          int r2 = row + dir.first;
          int c2 = col + dir.second;
          eight[nxt++] = isInside(r2, c2) && isEmpty(r2, c2);
  }
  int changes = 0;
  for (int j = 0; j < 8; j++) {
          if (eight[j] != eight[(j+1)%8]) {
                  changes++;
          }
  }
  if (changes > 2) {
          // more than 2 blocks of empty cells -> 2+ separate connected
  components return;
  }*/

  if (row == N - 1 && col == 0) {
    // the end
    if (i == N * N - 1) {
      answer++;
    }
    return;
  }
  for (int j = 0; j < 4; j++) {
    if (input[i] != '?' && input[i] != moves[j]) {
      continue;
    }
    const pair<int, int> &dir = dirs[j];
    int r2 = row + dir.first;
    int c2 = col + dir.second;
    if (isInside(r2, c2) && !visited[r2][c2]) {
      visited[r2][c2] = true;
      dfs(r2, c2, i + 1);
      visited[r2][c2] = false;
    }
  }
}

int main() {
  cin >> input;
  visited[0][0] = true;
  dfs(0, 0, 0);
  // visited[0][0] = false;
  cout << answer << "\n";
}
