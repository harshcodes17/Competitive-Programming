#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 1337;
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
        if(i != 1)
            cout << ' ';
        cout << i;
    }
    cout << '\n';
    return 0;

}