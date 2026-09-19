#include <bits/stdc++.h>
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

const int MAX_N = 400005;
const int MAX_BITS = 205;
vector<bitset<MAX_N>> columns(MAX_BITS);

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string t;
  cin >> t;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int j = 0; j < k; j++) {
    columns[j].reset();
    for (int i = 0; i < n; i++) {
      if (s[i][j] == t[j]) {
        columns[j].set(i);
      }
    }
  }
  bitset<MAX_N> ud;
  for (int i = 0; i < n; i++) {
    ud.set(i);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int g, r;
    cin >> g >> r;
    g--;
    r--;
    s[g][r] = (s[g][r] == 'o' ? 'x' : 'o');
    columns[r].flip(g);

    bitset<MAX_N> undetermined = ud;
    int a = 0;
    bool passed = false;
    for (int step = 0; step < k; step++) {
      if (!undetermined.test(g)) {
        break;
      }
      auto cu = undetermined & columns[step];
      int Cr = cu.count();
      if (a + Cr <= m) {
        if (cu.test(g)) {
          passed = true;
          break;
        }
        undetermined &= ~cu;
        a += Cr;
      } else {
        if (!cu.test(g)) {
          passed = false;
          break;
        }
        undetermined &= columns[step];
      }
    }
    if (passed) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  fastio();
  cout << fixed << setprecision(10);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
