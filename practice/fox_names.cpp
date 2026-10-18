#include <bits/stdc++.h>
#include <queue>
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
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  vector<pair<char, char>> con;
  vector<vector<char>> adj(26);
  vector<int> deg(26);
  for (int i = 0; i < n - 1; i++) {
    bool found = false;
    for (int j = 0; j < min(s[i].length(), s[i + 1].length()); j++) {
      if (s[i][j] != s[i + 1][j]) {
        found = true;
        adj[s[i][j] - 'a'].pb(s[i + 1][j]);
        con.pb({s[i][j], s[i + 1][j]});
        break;
      }
    }
    if (!found && s[i].length() > s[i + 1].length()) {
      cout << "Impossible" << nline;
      return;
    }
  }

  for (int i = 0; i < con.size(); i++) {
    if (deg[con[i].second - 'a'] == -1)
      deg[con[i].second - 'a'] = 0;
    deg[con[i].second - 'a']++;
  }
  queue<char> q;
  for (int i = 0; i < 26; i++) {
    if (deg[i] == 0) {
      q.push(i + 'a');
    }
  }
  if (q.empty()) {
    cout << "Impossible" << nline;
    return;
  }
  string res = "";
  while (!q.empty()) {
    char ch = q.front();
    res += ch;
    q.pop();
    for (int i = 0; i < adj[ch - 'a'].size(); i++) {
      deg[adj[ch - 'a'][i] - 'a']--;
      if (deg[adj[ch - 'a'][i] - 'a'] == 0) {
        q.push(adj[ch - 'a'][i]);
      }
    }
  }
  if (res.size() < 26) {
    cout << "Impossible" << nline;
    return;
  } else {
    cout << res << nline;
    return;
  }
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
