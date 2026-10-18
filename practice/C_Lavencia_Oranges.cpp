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

bool valid(int m, int n)
{
    ll cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cnt += 1LL * (m / i) * i;
        if (cnt >= n)
            return true;
    }
    return cnt >= n;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    int ans = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (valid(m, n))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << nline;
    ll cnt = 1;
    ll rem = n;
    for (int i = ans; i >= 1; i--)
    {
        ll ci = (ans / i);
        ll st = min(ci, (rem / i));
        for (int k = 0; k < st; k++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << cnt << " ";
            }
            cnt++;
        }
        rem -= i * st;
        if (rem <= 0)
            break;
    }
    cout << nline;
    return;
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