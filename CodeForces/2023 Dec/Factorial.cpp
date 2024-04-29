#include <bits/stdc++.h>

using namespace std;
long long factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}

int main(){
    long long hars=1;
    int num;
    cin>>num;
    hars = factorial(num);
    cout<<hars;
    return 0;

}