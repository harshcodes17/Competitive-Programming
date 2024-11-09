// 2024-11-07 08:05:51
// Author : Harshavardhan Bamane
// Linkedin: https://www.linkedin.com/in/harshavardhan-bamane-72b99a192/
// Codeforces: https://codeforces.com/profile/harsh_bamane17
// Codechef: https://www.codechef.com/users/harsh_bamane17

#include <bits/stdc++.h>

using namespace std;



//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define nl "\n"

//Typedef
typedef long long ll;
typedef vector<ll> vl;

vector <ll> primes;
vector <bool> is_prime;

// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }



int32_t main()
{
    fastio()
    Sieve(1e7+1);
    ll res = 0;
    vl v(1e7+1,0);
    for(int i=1;i*i<1e7+1;i++){
        for(int j=1;(i*i)+(2*(j*j*j*j))<1e7+1;j++){
            v[(i*i)+(2*(j*j*j*j))] = 1;
        }
    }
    vl pre(1e7+1,0);
    for(int i=0;i<1e7+1;i++){
        if(v[i]&&is_prime[i]){
            pre[i] = 1;
        }
    }
    for(int i=1;i<1e7+1;i++){
        pre[i] += pre[i-1];
    }
    int t;
    t=1;
    cin>>t;
    auto solve = [&] () {
        ll n;
        cin>>n;
        cout<<pre[n]<<nl;
    };
    while(t--)
    {
        solve();
    }
    
    return 0;
}