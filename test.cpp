#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;


int inp() {
    int x;
    cin >> x;
    return x;
}

vector<int> linp() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

void solve() {
    int a, b, c;
    a = inp();
    b = inp();
    c = inp();

    vector<int> x = linp();

    vector<long long> prefix_sum(a + 1, 0);
    for (int i = 1; i <= a; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + x[i - 1];
    }

    long long ans = -1e18;
    long long max_sum = 0;
    for (int i = 1; i <= a; ++i) {
        max_sum += x[i - 1];
        if (i >= b) {
            ans = max(ans, max_sum);
        }
        if (i >= c) {
            max_sum -= x[i - c];
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
