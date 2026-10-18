#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
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

// Vector IO
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (int i = 0; i < sz(v); ++i)
        out << v[i] << (i == sz(v) - 1 ? "" : " ");
    return out;
}

//   observations
// let the robot be in (x, y) initially;
// let m(x, y) = (x + y);
// the robot can go to(x, y + 1), (x + 1, y) or (x - 1, y - 1);
// for these points m(x, y + 1) = x + y + 1, m(x + 1, y) = x + y + 1, m(x - 1, y - 1) = x + y + 1 - 3;
// for all these the modulo 3 is constant; and is m(x,y)%3 + 1;
// if i go to another second then the modulo becomes m(x,y)%3 +2;
// so (m(xt,yt)%3 - t%3 + 3)%3 = constant = m(x,y)%3=c;
// so each of the 2n -1 diagonals can be grouped into a single modulo 3 group
// suppose m(x,y)%3=k
// then there exactly (2n-1)/3 diagonal with v%3 = k;
// so it has to be one of them
// so it can start at top right diagonal with with modulo k and come towards bottom left
// if found then nice else the modulo right now would be k + 2*n - 1 % 3

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    if (n == 2)
    {
        ans.pb(3);
        ans.pb(3);
        ans.pb(3);
    }
    else if (n % 3 == 2)
    {
        for (int i = 2 * n - 2; i >= 4; i -= 2)
        {
            ans.pb(i);
        }
        for (int i = 2 * n - 1; i >= 3; i -= 2)
        {
            ans.pb(i);
        }
        for (int i = 2 * n - 2; i >= 4; i -= 2)
        {
            ans.pb(i);
        }
    }
    else
    {
        for (int i = 2 * n - 2; i >= 4; i -= 2)
        {
            ans.pb(i);
        }
        for (int i = 2 * n - 2; i >= 4; i -= 2)
        {
            ans.pb(i);
        }
        for (int i = 2 * n - 2; i >= 4; i -= 2)
        {
            ans.pb(i);
        }
    }
    cout << ans.size() << nline;
    for (auto x : ans)
        cout << x << " ";
    cout << nline;
}

int main()
{
    fastio();
    cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}