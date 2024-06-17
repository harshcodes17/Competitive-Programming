#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
int spf[N], occupied[N], isActive[N];
 
void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i;
 
    for(int i = 2; i < N; i++) {
        for(int j = 2 * i; j < N; j += i) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

vector<int>primeFactorise(int n) {
    vector<int>primes;
    while(n != 1) {
        int x = spf[n];
        while(n % x == 0) n /= x;
        primes.push_back(x);
    }
    return primes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        char t; int x; cin >> t >> x;
        vector<int>primes = primeFactorise(x);

        if(t == '+') {
            if(isActive[x]) cout << "Already on\n";
            else {
                int collision = 0;

                for(auto &i : primes) if(occupied[i]) collision = occupied[i];

                if(collision) cout << "Conflict with " << collision << "\n";
                else {
                    cout << "Success\n";
                    for(auto &i : primes) occupied[i] = x;
                    isActive[x] = 1;
                }
            }
        }
        else {
            if(!isActive[x]) cout << "Already off\n";
            else {
                cout << "Success\n";
                isActive[x] = 0;
                for(auto &i : primes) occupied[i] = 0;
            }
        }
    }
}