/*
Problem Name: Sliding Median
Problem Link: https://cses.fi/problemset/task/1076
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

void solve(){
    int n,k; see(n,k);
    priority_queue<pii> l; 
    priority_queue<pii,vii,greater<pii>> r;
    int a[n+1];
    seea(a,0,n);
    int m = (k+1)/2, b=0;
    rep(i,0,n){
        
        while(!r.empty() && r.top().S<=i-k) r.pop();
        while(!l.empty() && l.top().S<=i-k) l.pop();
        if (b<m){ 
            r.push({a[i],i});
            l.push(r.top()); r.pop();
            b++;
        }
        else{ 
            l.push({a[i],i}); r.push(l.top());
            l.pop();
        }
        while(!r.empty() && r.top().S<=i-k) r.pop();
        while(!l.empty() && l.top().S<=i-k) l.pop();
        if (i<k-1) continue;
        put(l.top().F);
        if (a[i-k+1]<=l.top().F) b--;
    }
}    
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}