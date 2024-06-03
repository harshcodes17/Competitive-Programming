#include <bits/stdc++.h>
using namespace std;

vector<int> parseIPorMask(const string& str) {
    stringstream ss(str);
    string token;
    vector<int> result;
    while (getline(ss, token, '.')) {
        result.push_back(stoi(token));
    }
    return result;
}

vector<int> getNetworkAddress(const vector<int>& ip, const vector<int>& mask) {
    vector<int> networkAddress(4);
    for (int i = 0; i < 4; ++i) {
        networkAddress[i] = ip[i] & mask[i];
    }
    return networkAddress;
}

int calculateHosts(const vector<int>& mask) {
    int hostBits = 0;
    for (const int& part : mask) {
        hostBits += bitset<8>(~part).count();
    }
    return hostBits ? (1 << hostBits) - 2 : 0;
}

string networkAddressToString(const vector<int>& networkAddress) {
    stringstream ss;
    for (int i = 0; i < 4; ++i) {
        if (i != 0) ss << ".";
        ss << networkAddress[i];
    }
    return ss.str();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string ip, mask;
        cin >> ip >> mask;

        vector<int> ipParts = parseIPorMask(ip);
        vector<int> maskParts = parseIPorMask(mask);

        vector<int> networkAddress = getNetworkAddress(ipParts, maskParts);
        int hostCount = calculateHosts(maskParts);

        cout << hostCount << endl;
        cout << networkAddressToString(networkAddress) << endl;
    }
    return 0;
}