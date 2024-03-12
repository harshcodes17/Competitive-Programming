#include <iostream>
#include <vector>
using namespace std;

bool backtrack(int idx, int curr, const vector<int>& angles) {
    if (idx==angles.size()){
        return curr%360==0;
    }
    if (backtrack(idx + 1,(curr+angles[idx])%360,angles)) {
        return true;
    }
    if (backtrack(idx+1,(curr-angles[idx]+360)%360,angles)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> angles(n);
    for (int i = 0; i < n; ++i) {
        cin >> angles[i];
    }
    if (backtrack(0, 0, angles)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
