#include <bits/stdc++.h>
using namespace std;

// Macros
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

// Typedef
typedef long long ll;
typedef vector<ll> vl;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vl a(n);
    for (ll &x : a) cin >> x;
    vl b(n);
    for (ll &x : b) cin >> x;

    // Min-heap using greater comparator
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < m; i++) {
        pq.push({0, i});
    }

    for (int i = 0; i < n; i++) {
        ll num = b[i];
        ll val = a[i];

        if (num == m) {
            vector<pair<ll, ll>> temp;
            while (!pq.empty()) {
                auto topElement = pq.top();
                pq.pop();
                topElement.first += val;
                temp.push_back(topElement);
            }
            for (auto &elem : temp) {
                pq.push(elem);
            }
        } else {
            while (num > 0) {
                auto topElement = pq.top();
                pq.pop();
                topElement.first += val;
                pq.push(topElement);
                num--;
            }
        }
    }

    vl ans(m);
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        ans[x.second] = x.first;
    }
    for (const auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
}

int main() {
    solve();
    return 0;
}