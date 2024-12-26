#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//PBDS
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define nl "\n"
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,V>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }
template<typename T, typename V> // cout << vector<pair<T,V>>
ostream& operator<<(ostream &ostream, const vector<pair<T,V>> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

//Constants
vector <ll> primes;
vector <bool> is_prime;

// Mathematical functions


/**
 * @brief Sieve for primes and smallest prime factors (SPF)
 * 
 * This function generates all prime numbers up to a given number n using the Sieve of Eratosthenes algorithm.
 * 
 * @param n The upper limit (inclusive) for generating prime numbers.
 * @return vector<ll> A vector containing all prime numbers up to n.
 */
vector<ll> Sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<ll> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

unordered_map<ll, ll> prime_factorization(ll n, vector<ll>& primes) {
    unordered_map<ll, ll> factors;
    for (ll i = 0; primes[i] * primes[i] <= n && i < primes.size(); i++) {
        while (n % primes[i] == 0) {
            factors[primes[i]]++;
            n /= primes[i];
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

vector<unordered_map<ll, ll>> precompute_factorials(ll n, vector<ll>& primes) {
    vector<unordered_map<ll, ll>> factorial_factors(n + 1);
    for (ll m = 2; m <= n; m++) {
        unordered_map<ll, ll> factors = prime_factorization(m, primes);
        factorial_factors[m] = factorial_factors[m - 1];
        for (auto& factor : factors) {
            factorial_factors[m][factor.first] += factor.second;
        }
    }
    return factorial_factors;
}

ll total(unordered_map<ll, ll>& factors) {
    ll cnt = 1;
    for (auto& factor : factors) {
        cnt = (cnt * (factor.second + 1)) % M;
    }
    return cnt;
}

int32_t main()
{
    fastio()
    
    auto solve = [&] () {
        ll n, m;
        cin >> n >> m;
        vl v(n);
        cin >> v;
        vl primes = Sieve(10000);
        vector<unordered_map<ll, ll>> factorial_factors = precompute_factorials(m, primes);
        for (int i = 0; i < n; i++) {
            unordered_map<ll, ll> facts = prime_factorization(v[i], primes);
            for (auto& factor : factorial_factors[m]) {
                facts[factor.first] += factor.second;
            }
            cout << total(facts) << " ";
        }
        cout << nl;
    };

    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
