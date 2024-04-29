#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int z = 0, o = 0;
        for (char ch : s) {
            if (ch == '0') z++;
            else if (ch == '1') o++;
        }

        string ans = "";
        for (char ch : s) {
            if (ch == '0' && o < 1) break;
            if (ch == '1' && z < 1) break;
            if (ch == '0' && o > 0) {
                ans += '1';
                o--;
            } else if (ch == '1' && z > 0) {
                ans += '0';
                z--;
            }
        }

        cout << abs(static_cast<int>(s.length() - ans.length())) << endl;
    

    
    }
    return 0;
}