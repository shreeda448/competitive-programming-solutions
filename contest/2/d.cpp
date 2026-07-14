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
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<int> posA(n + 2, n + 1);
  vector<int> posB(n + 2, n + 1);
  vector<int> nxtA(n + 2, n + 1);
  vector<int> nxtB(n + 2, n + 1);

  for (int i = n; i >= 1; i--) {
    if (a[i] + 1 <= n + 1) {
      nxtA[i] = posA[a[i] + 1];
    }
    posA[a[i]] = i;

    if (b[i] + 1 <= n + 1) {
      nxtB[i] = posB[b[i] + 1];
    }
    posB[b[i]] = i;
  }

  vector<int> M_div(n + 2, n + 1);
  for (int i = n; i >= 1; i--) {
    if (a[i] == b[i]) {
      int nA = nxtA[i];
      int nB = nxtB[i];
      if (nA == nB) {
        M_div[i] = M_div[nA];
      } else {
        M_div[i] = min(nA, nB);
      }
    }
  }

  vector<int> first_1_A(n + 2, n + 1);
  vector<int> first_1_B(n + 2, n + 1);
  for (int i = n; i >= 1; i--) {
    first_1_A[i] = (a[i] == 1) ? i : first_1_A[i + 1];
    first_1_B[i] = (b[i] == 1) ? i : first_1_B[i + 1];
  }

  ll ans = 0;
  for (int L = 1; L <= n; L++) {
    int i_A = first_1_A[L];
    int i_B = first_1_B[L];
    int M;
    if (i_A == i_B) {
      M = M_div[i_A];
    } else {
      M = min(i_A, i_B);
    }
    ans += (M - L);
  }
  cout << ans << "\n";
}

int main() {
  fastio();
  int multTestQ;
  cin >> multTestQ;
  while (multTestQ--) {
    solve();
  }
  return 0;
}
