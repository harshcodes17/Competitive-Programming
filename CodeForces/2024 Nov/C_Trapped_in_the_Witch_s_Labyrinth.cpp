// 2024-12-01 10:14:20
// Author : Harshavardhan Bamane
// Linkedin: https://www.linkedin.com/in/harshavardhan-bamane-72b99a192/
// Codeforces: https://codeforces.com/profile/harsh_bamane17
// Codechef: https://www.codechef.com/users/harsh_bamane17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// PBDS
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define nl "\n"
#define IOtext                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for (int i = j; i < k; i += in)
#define rforeach(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j, k) foreach (i, j, k, 1)
#define rrep(i, j, k) rforeach(i, j, k, 1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) \
    int x;       \
    cin >> x;
#define inll(x)      \
    long long int x; \
    cin >> x;
#define instr(x) \
    string x;    \
    cin >> x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pm cout << "-1" << endl
#define ps(x, y) fixed << setprecision(y) << x

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef set<int> st;

// Operator overloads
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
template <typename T, typename V> // cout << map<T,V>
ostream &operator<<(ostream &ostream, const map<T, V> &c)
{
    for (auto &it : c)
        cout << it.first << " " << it.second << endl;
    return ostream;
}
template <typename T, typename V> // cout << vector<pair<T,V>>
ostream &operator<<(ostream &ostream, const vector<pair<T, V>> &c)
{
    for (auto &it : c)
        cout << it.first << " " << it.second << endl;
    return ostream;
}

// Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bits
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Check
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Constants
vector<ll> primes;
vector<bool> is_prime;

// Mathematical functions
void Sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// To find modulo inverse, call powermod(A,M-2,M)

int32_t main()
{
    fastio();

    auto solve = [&]()
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        if (n == 1 && m == 1)
        {
            out(0);
            return;
        }

        queue<pi> q;
        vvi vis(n, vi(m, 0));
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                if ((i == 0 && a[i][j] == 'U') || (i == n - 1 && a[i][j] == 'D') || (j == 0 && a[i][j] == 'L') || (j == m - 1 && a[i][j] == 'R'))
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 'D')
            {
                vis[i - 1][j] = 1;
                q.push({i - 1, j});
            }
            if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 'R')
            {
                vis[i][j - 1] = 1;
                q.push({i, j - 1});
            }
            if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 'U')
            {
                vis[i + 1][j] = 1;
                q.push({i + 1, j});
            }
            if (j + 1 < m && !vis[i][j + 1] && a[i][j + 1] == 'L')
            {
                vis[i][j + 1] = 1;
                q.push({i, j + 1});
            }

            auto check = [&](int ii, int jj)
            {
                if (ii < 0 || ii >= n || jj < 0 || jj >= m)
                    return;
                if (vis[ii][jj] || a[ii][jj] != '?')
                    return;
                if (ii - 1 >= 0 && !vis[ii - 1][jj])
                    return;
                if (jj - 1 >= 0 && !vis[ii][jj - 1])
                    return;
                if (ii + 1 < n && !vis[ii + 1][jj])
                    return;
                if (jj + 1 < m && !vis[ii][jj + 1])
                    return;
                vis[ii][jj] = 1;
                q.push({ii, jj});
            };

            check(i - 1, j);
            check(i + 1, j);
            check(i, j - 1);
            check(i, j + 1);
        }

        int ans = 0;
        rep(i, 0, n) rep(j, 0, m) if (vis[i][j] == 0) ans++;
        out(ans);
    };

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
