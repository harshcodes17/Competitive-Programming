#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>>v(5,vector<int>(5));
    int arr[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    int ith;
    int jth;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==1){
                ith = i;
                jth = j;
                break;
            }
        }
    }
    int sum = (abs(2-ith)+abs(2-jth));
    cout<<sum;
    return 0;

}