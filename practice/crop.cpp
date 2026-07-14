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
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  for (int row = 0; row < H; row++) {
    cin >> grid[row];
  }
  int topIdx = -1, bottomIdx = -1, leftIdx = -1, rightIdx = -1;

  for (int i = 0; i < H; i++) {
    int number_of_hashes = 0;
    for (char ch : grid[i]) {
      if (ch == '#') {
        number_of_hashes++;
      }
    }
    if (number_of_hashes > 0) {
      topIdx = i;
      break;
    }
  }

  for (int i = H - 1; i >= 0; i--) {
    int number_of_hashes = 0;
    for (char ch : grid[i]) {
      if (ch == '#') {
        number_of_hashes++;
      }
    }
    if (number_of_hashes > 0) {
      bottomIdx = i;
      break;
    }
  }

  for (int i = W - 1; i >= 0; i--) {
    int number_of_hashes = 0;
    for (int j = 0; j < H; j++) {
      if (grid[j][i] == '#') {

        number_of_hashes++;
      }
    }
    if (number_of_hashes > 0) {
      rightIdx = i;
      break;
    }
  }
  for (int i = 0; i < W; i++) {
    int number_of_hashes = 0;
    for (int j = 0; j < H; j++) {
      if (grid[j][i] == '#') {
        number_of_hashes++;
      }
    }
    if (number_of_hashes > 0) {
      leftIdx = i;
      break;
    }
  }
  if (rightIdx == -1 || leftIdx == -1 || topIdx == -1 || bottomIdx == -1) {
    cout << nline;
    return;
  }
  for (int i = topIdx; i <= bottomIdx; i++) {
    for (int j = leftIdx; j <= rightIdx; j++) {
      cout << grid[i][j];
    }
    cout << nline;
  }
  cout << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
