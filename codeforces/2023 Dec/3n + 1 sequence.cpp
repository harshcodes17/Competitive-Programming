#include <bits/stdc++.h>

using namespace std;

int threeplusone(int num,int c){
        c++;
        if(num==1){
            return c;
        }
        else if(num%2==0){
            return threeplusone(num/2,c);
        }
        else if(num%2==1){
            return threeplusone(3*num+1,c);
        }
        
        

}

int main(){
    int n;
    cin>>n;
    int c=0;
    int ans = threeplusone(n,c);
    cout<<ans;
    return 0;

}