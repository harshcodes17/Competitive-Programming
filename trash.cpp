// #include <bits/stdc++.h>
// #define fopenn(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
// #define compile (1.0 * clock() / CLOCKS_PER_SEC)
// using namespace std;
// //void debug()
// //{
// //
// //}
// struct p
// {
//     int32_t l, r;
//     p() : l(0), r(0) {}
//     p(int32_t a, int32_t b) : l(a), r(b) {}
// };

// signed main(void)
// {
//     fopenn("");
//     ios_base::sync_with_stdio(false); cin.tie(nullptr);
//     int t = 0; cin >> t;
//     while (t--)
//     {
//         string s; cin >> s;
//         string res; p fr, sr;
//         int32_t f1p = -1;
//         for (int32_t i = 0; i < s.size(); i++)
//             if (s[i] == '1')
//             {
//                 f1p = i;
//                 res = s.substr(i);
//                 fr = p(i, s.size() - 1);
//                 break;
//             }

//         if (res.empty())  cout << "1 1 1 1\n";
//         else
//         {
//             int32_t zlen = 0, fzp = -1;
//             for (int32_t i = 0; i < res.size(); i++)
//             {
//                 if (res[i] == '0')
//                 {
//                     fzp = i;
//                     zlen = res.size() - i;
//                     break;
//                 }
//             }

//             if (zlen == 0)
//             {
//                 for (int32_t i = 0; i < s.size(); i++)
//                 {
//                     if (s[i] == '0')
//                     {
//                         sr = p(i, i);
//                         break;
//                     }
//                 }
//             }
//             else
//             {
//                 sr = p(0, 0);
//                 string bst = res;
//                 for (int32_t i = 0; i + zlen <= s.size(); i++)
//                 {
//                     string tmp = res;
//                     for (int32_t j = i; j < i + zlen; j++) tmp[j - i + fzp] = ((tmp[j - i + fzp] - '0') ^ (s[j] - '0')) + '0';
//                     if (tmp > bst)
//                     {
//                         bst = tmp;
//                         sr = p(i, i + zlen - 1);
//                     }
//                 }
//             }
//             cout << fr.l + 1 << ' ' << fr.r + 1 << ' ' << sr.l + 1 << ' ' << sr.r + 1 << '\n';
//         }
//     }
//     cerr << '\n' << "Done in: " << compile << " s\n";
//     return 0;
// }
#include <bits/stdc++.h>
#define fopenn(tenfile)                       \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define compile (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

signed main(void)
{
    fopenn("")
        ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int32_t i = 0, j = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
            break;
            }
        }
        if (i == s.size()) {
            i = s.size() - 1;
        }
        int32_t d = i - 1;
        for (j = i; j < s.size() && d >= 0; j++, d--) {
            if (s[j] == '1') {
            break;
            }
        }
        d++;
        cout << 1 << " " << s.size() << " " << d + 1 << " " << d + s.size() - i << '\n';
    }
    cerr << '\n'
         << "Done in: " << compile << " s\n";
    return 0;
}