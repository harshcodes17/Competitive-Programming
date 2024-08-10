#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define deb(x...)
#endif

const int mod = 1000000007; // 998244353;
const int N = 2 * 1e5 + 5;

ll fact[N];
int modInverse(int A, int M)
{
	int m0 = M;
	int y = 0, x = 1;
	if (M == 1) return 0;
	while (A > 1) {
		int q = A / M;
		int t = M;
		M = A % M, A = t, t = y, y = x - q * y, x = t;
	}
	if (x < 0) x += m0;
	return x;
}
void init() {
	fact[0] = fact[1] = 1;
	for (ll i = 2; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
}
// O(log(mod))
ll nCr(int n, int r) {
	if (r > n) return 0;
	return fact[n] * modInverse(fact[r] * fact[n - r] % mod , mod) % mod;
}
// O(log(mod))
ll catalan(int n) {
	/* factorial 2*n is needed*/
	return fact[2 * n] * modInverse(fact[n + 1] * fact[n] % mod , mod) % mod;
}
void add(int &a, int b) {
	a = ((a % mod) + (b % mod)) % mod;
}
void mul(int &a, int b) {
	a = ((a % mod) * (b % mod)) % mod;
}
void divide(int &a, int b) {
	mul(a, modInverse(b, mod));
}
void substract(int &a, int b) {
	a = (a - b + mod) % mod;
}

void solve()
{

	int n, k, ones = 0;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], ones += a[i];

	int ans = 0;

	for (int i = k / 2 + 1; i <= min(k, ones); i++) {
		int o = i;
		int z = k - i;

		int a1 = nCr(ones, o);
		int a2 = nCr(n - ones, z);

		mul(a1, a2);

		add(ans, a1);
	}

	cout << ans << "\n";


}

signed main()
{
	init();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
