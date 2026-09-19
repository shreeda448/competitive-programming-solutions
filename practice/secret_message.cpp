#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

// Fast I/O
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define nline "\n"
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// Typedefs
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// vector IO
template <typename T> istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<bitset<26>> sk(n);
  vector<string> ek(k);
  string res;
  for (int i = 0; i < k; i++) {
    cin >> ek[i];
  }
  // for each of the n positions check which characters are available
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      sk[i].set(ek[j][i] - 'a');
    }
  }
  for (int d = 1; d <= n; d++) {
    if (n % d != 0)
      continue;
    bool possible = true;
    bitset<26> bt;
    string s = "";
    for (int i = 0; i < d; i++) {
      bt = sk[i];
      for (int j = i; j < n; j += d) {
        bt &= sk[j];
      }
      if (!bt.any()) {
        possible = false;
        break;
      }
      int pos = bt._Find_first();
      s += (char)('a' + pos);
    }
    if (possible) {
      for (int i = 0; i < n; i++) {
        res += s[i % d];
      }
      break;
    }
  }
  cout << res << nline;
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
