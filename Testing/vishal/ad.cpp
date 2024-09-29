#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 16; i < 17; i++)
    {
        string input = "./testfilesad/in" + to_string(i) + ".txt";
        string output = "./testfilesad/out" + to_string(i) + ".txt";
        freopen(input.c_str(), "r", stdin);
        freopen(output.c_str(), "w", stdout);

        ll t;
        cin >> t;
        while (t--)
        {
            ll n, k;
            cin >> n >> k;
            ll m = 0;
            priority_queue<ll> pq;
            while (k--)
            {
                ll l, r;
                cin >> l >> r;
                if (l == 2)
                {
                    m = max(m, r);
                }
                else
                {
                    pq.push(r);
                }
            }
            ll cnt = 0;
            while (!pq.empty() && pq.top() > m)
            {
                cnt += 1;
                pq.pop();
            }
            cout << (n - m - cnt) << endl;
        }
    }
    return 0;
}
