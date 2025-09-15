// 2025-06-24 22:10:47
// Author : Harshavardhan Bamane
// Linkedin: https://www.linkedin.com/in/harshavardhan-bamane-72b99a192/
// Codeforces: https://codeforces.com/profile/harsh_bamane17
// Codechef: https://www.codechef.com/users/harsh_bamane17

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
#define int long long


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
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
//To find modulo inverse, call powermod(A,M-2,M)

int32_t main()
{
    fastio()
    
    auto solve = [&] () {
        ll n;
        cin>>n;
        vl v(n);
        cin>>v;
        // map<ll,ll>mp;
        // for(auto x:v)
        // {
        //     mp[x]++;
        // }
        // sort(all(v));
        // ll ans = 0;

        // ll p1=0,p2=1,p3=2;

        // while(p3<n){
        //     ll sum_first_two = v[p1] + v[p2];
        //     ll total_sum = v[p1] + v[p2] + v[p3];
        //     // cout<<"p1: "<<p1<<" p2: "<<p2<<" p3: "<<p3<<nl;
        //     // cout<<"sum_first_two: "<<sum_first_two<<" total_sum: "<<total_sum<<nl;
        //     // cout<<"v[p1]: "<<v[p1]<<" v[p2]: "<<v[p2]<<" v[p3]: "<<v[p3]<<nl;
            
        //     auto it = lower_bound(all(v), total_sum);
        //     //if outside has the problem
        //     //if found element equal or greater than total_sum bob wins

        //     if(it != v.end() && *it >= total_sum){
        //         //we can color it
        //         p1++;
        //         p2++;
        //         p3++;
        //     }
        //     else{
        //         if(sum_first_two <= v[p3]){
        //             if(p3==n-1){
        //                 cout<<ans<<nl;
        //                 return;
        //             }
        //             else{
        //                 p1++;
        //                 p2++;
        //                 if(p2==p3){
        //                     p3++;
        //                 }
        //             }
                    
        //         }
        //         else{
        //             cout<<"p1: "<<p1<<" p2: "<<p2<<" p3: "<<p3<<nl;
        //             cout<<"v[p1]: "<<v[p1]<<" v[p2]: "<<v[p2]<<" v[p3]: "<<v[p3]<<nl;
        //             // cout<<"sum_first
        //             cout<<"hi"<<nl;
        //             cout<<"ans: "<<ans<<nl;
        //             //we got a triplet 
        //             ans++;
        //             p1++;
        //             p2++;
        //             if(p2==p3){
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        // cout<<ans<<nl;

        ll ans = 0;

        // sort(all(v));
        // cout<<v<<nl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                ll sum = v[i] + v[j];
                
                auto it = lower_bound(v.begin()+(j+1), v.end(), sum)-v.begin();  
                // cout<<it-v.begin()<<nl; 
                auto it2 = upper_bound(v.begin()+(j+1),v.end(),v[n-1]-sum+1)-v.begin();
                // cout<<it2-v.begin()<<nl;

                if(it2<=it-1){
                    ans+=(it-it2);
                }
                

            }
        }
        cout << ans << nl;

    };

    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}