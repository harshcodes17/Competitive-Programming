#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, q;
        cin >> n >> q;
        vector<long long> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];
        }

        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        // Prepare to count frequency of segment coverage
        vector<long long> freq(n + 1, 0);
        
        // Efficiently calculate segments
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                freq[j - i + 1]++;
            }
        }

        // Answer the queries
        for (int i = 0; i < q; ++i) {
            if (queries[i] <= n) {
                cout << freq[queries[i]] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}
