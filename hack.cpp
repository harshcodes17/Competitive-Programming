#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3e5 + 100;
struct node {
    unsigned long long a;
    long long b;
};
bool cmp(node c,node d){
    return c.b<d.b;
}
void solve()
{
    long long n,k,cnt=0;
    unsigned long long  a[N]={0};
    node s[N];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin >> s[i].a;
    for(int i=0;i<n;i++) {
        cin >> s[i].b;
        if(s[i].b<0)
            s[i].b=-s[i].b;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        a[s[i].b]=a[cnt]+s[i].a;
        cnt=s[i].b;
    }
    for(int i=1;i<=n;i++) {
        unsigned long long sum=k*i;
        if (sum < a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}