#include <bits/stdc++.h>

using namespace std;
//hi
int main(){
    int var = 0;

    int n;
    cin>>n;
    
    while(n--){
        string temp = "";
        cin>>temp;
        if(temp=="X++" || temp =="++X"){
            var++;
        }
        else if(temp=="--X"||temp=="X--"){
            var--;
        }
        
    }
    cout<<var<<endl;
    return 0;

}