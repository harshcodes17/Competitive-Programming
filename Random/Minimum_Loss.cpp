#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> prices(n); // pair of (price, original index)
    for (int i = 0; i < n; ++i) {
        cin >> prices[i].first;
        prices[i].second = i;
    }

    // Sort prices based on the price value
    sort(prices.begin(), prices.end());

    ll ans = 1e12;

    // Iterate through the sorted prices to find the minimum loss
    for (int i = 1; i < n; ++i) {
        if (prices[i].second < prices[i - 1].second) {
            ans = min(ans, prices[i].first - prices[i - 1].first);
        }
    }

    cout << ans << endl;

    return 0;
}