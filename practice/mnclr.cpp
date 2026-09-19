#include "bits/stdc++.h"
using namespace std;
#define nline '\n';
int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n - 1; i++) {
    cout << s[i] << 'o';
  }
  cout << s[n - 1] << nline;
  return 0;
}
