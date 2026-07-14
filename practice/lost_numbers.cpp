#include <bits/stdc++.h>
#include <cstdio>
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

pair<int, int> factors[967];

int main() {
  factors[32] = {4, 8};
  factors[60] = {4, 15};
  factors[64] = {4, 16};
  factors[92] = {4, 23};
  factors[168] = {4, 42};
  factors[120] = {8, 15};
  factors[128] = {8, 16};
  factors[184] = {8, 23};
  factors[336] = {8, 42};
  factors[240] = {15, 16};
  factors[345] = {15, 23};
  factors[630] = {15, 42};
  factors[368] = {16, 23};
  factors[672] = {16, 42};
  factors[966] = {23, 42};
  vector<int> a(6);
  int prod1, prod2;
  int b = 1, c = 2;
  cout << "? " << b << " " << c << nline;
  fflush(stdout);
  cin >> prod1;
  b = 2, c = 3;
  cout << "? " << b << " " << c << nline;
  fflush(stdout);
  cin >> prod2;
  int arr[4] = {factors[prod2].first, factors[prod2].second,
                factors[prod1].first, factors[prod1].second};
  sort(arr, arr + 4);
  for (int i = 0; i < 3; i++) {
    if (arr[i] == arr[i + 1]) {
      a[1] = arr[i];
      a[0] = prod1 / a[1];
      a[2] = prod2 / a[1];
      break;
    }
  }
  b = 3, c = 4;
  cout << "? " << b << " " << c << nline;
  fflush(stdout);
  cin >> a[3];
  a[3] /= a[2];
  b = 4, c = 5;
  cout << "? " << b << " " << c << nline;
  fflush(stdout);
  cin >> a[4];
  a[4] /= a[3];
  a[5] = 108 - a[0] - a[1] - a[2] - a[3] - a[4];
  cout << "! ";
  for (auto x : a)
    cout << x << " ";
  cout << nline;
  fflush(stdout);
  return 0;
}
