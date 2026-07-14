#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

// b x x+y c
// case 1 : happiness = 2x-b-c-y+2x+2y-b-c = 4x+y-2b-2c = (2x+y-b-c)+(2x-b-c)
// case 2 : happiness = 3x+3y-b-x-c= 2x+3y-b-c= (2x+y-b-c)+(2y)
// if(2x-b-c>2y) then choose case 1 else choose case 2

void solve() {}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
