#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 5;
vector<int> tree[5 * N];
int A[N];

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        res.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

void build(int curr, int l, int r)
{
    if (l == r)
    {
        tree[curr].push_back(A[l]);
        return;
    }
    int md = l + (r - l) / 2;
    build(2 * curr + 1, l, md);
    build(2 * curr + 2, md + 1, r);
    tree[curr] = merge(tree[2 * curr + 1], tree[2 * curr + 2]);
}
int query(int curr, int l, int h, int x, int y, int k, int k2)
{
    if (l > y || h < x)
        return 0; // Out of range
    if (l >= x && h <= y)
    {
        int sz = tree[curr].size();
        int less_that_equal_k2 = (upper_bound(tree[curr].begin(), tree[curr].end(), k2) - tree[curr].begin());
        int less_than_k = lower_bound(tree[curr].begin(), tree[curr].end(), k) - tree[curr].begin();
        return less_than_k - less_that_equal_k2;
    }
    int md = l + (h - l) / 2;
    return query(2 * curr + 1, l, md, x, y, k, k2) + query(2 * curr + 2, md + 1, h, x, y, k, k2);
}
void clean(int n)
{
    for (int i = 0; i <= 5 * n; ++i)
        tree[i].clear();
    for (int i = 0; i <= n; ++i)
        A[i] = 1e9;
}
void solve()
{

    int n, q;
    cin >> n >> q;
    clean(n);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        vp.push_back({u, v});
    }
    sort(vp.begin(), vp.end());
    vector<int> ghosts;
    vector<int> humans;
    for (int i = 0; i < n; ++i)
    {
        humans.push_back(vp[i].first);
        A[i] = vp[i].second;
    }
    build(0, 0, n - 1);
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mnIdx = upper_bound(humans.begin(), humans.end(), a) - humans.begin();
        int mxIdx = prev(lower_bound(humans.begin(), humans.end(), b)) - humans.begin();
        if (mnIdx >= 0 and mnIdx < n and mxIdx >= mnIdx)
        {
            cout << query(0, 0, n - 1, mnIdx, mxIdx, d, c) << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int z = 0; z < 6; z++)
    {
        freopen(("in" + to_string(z) + ".txt").c_str(), "r", stdin);   // Correctly opens input file for reading
        freopen(("out" + to_string(z) + ".txt").c_str(), "w", stdout); // Correctly opens output file for writing

        int t;
        cin >> t;
        while (t--)
            solve();
    }
    return 0;
}