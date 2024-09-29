#include <bits/stdc++.h>
#include "testlib.h"
#include <vector>
using namespace std;
#define ll long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char **argv)
{
    for (int i = 16; i < 17; i++)
    {
        string output = "./testfilesad/in" + to_string(i) + ".txt";
        freopen(output.c_str(), "w", stdout);
        registerGen(argc, argv, 1);

        int test_count = opt<int>("test-count");
        int sum_n = opt<int>("sum-n");
        int min_n = opt<int>("min-n", 1);
        // int char_bias = opt<int>("char-bias", 0);

        // string alphabet = "abcdefghijklmnopqrstuvwxyz";

        vector<int> q_list = rnd.partition(test_count, sum_n, min_n);

        println(test_count);
        for (int test_case = 0; test_case < test_count; ++test_case)
        {
            int q = q_list[test_case];
            // string str;
            // cerr << "n: " << n << ", wnext range: [1, " << n / 2 << "]\n";
            // long long diff = rnd.wnext(10000000000, 0);
            uniform_int_distribution<int64_t> nl(1, 10000000000);
            uniform_int_distribution<int64_t> o(1, 2);

            ll n = 10000000000;
            while (n < q)
            {
                n = nl(rng);
            }
            cout << n << " " << q << endl;
            uniform_int_distribution<int64_t> nop(1, n);
            unordered_set<ll> us;
            for (int i = 0; i < q; ++i)
            {
                ll no = nop(rng);
                ll opt = rnd.wnext(1, 2, 1);
                while (us.find(no) != us.end())
                {
                    ll no = nop(rng);
                    int opt = rnd.wnext(1, 2);
                }
                us.insert(no);
                cout << opt << " " << no << endl;
            }
            // println(diff);
        }
    }
}
