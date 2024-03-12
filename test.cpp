vector<int> f(int n) {
    vector<int> v(3, 0);
    for (int i = 2; i <= 5; i += i == 2 ? 1 : 2) {
        while (n % i == 0) {
            n /= i;
            v[i == 2 ? 0 : i == 3 ? 1 : 2]++;
        }
    }
    return n == 1 ? v : vector<int>();
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<int> v1 = f(x);
    vector<int> v2 = f(y);

    if (v1.empty() || v2.empty()) {
        cout << -1 << endl;
    } else {
        int n = 0;
        for (int i = 0; i < 3; ++i) {
            n += abs(v1[i] - v2[i]);
        }
        cout << n << endl;
    }

    return 0;
}