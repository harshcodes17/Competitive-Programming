#include <stdio.h>

int main(){

<<<<<<< HEAD
    int y=3;
    int z = (--y) + (y=10);
    printf("%d\n", z);
    
    return 0;
=======
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int count = 0;
    int arr2[n];
    for(int i=0;i<n;i++){
        arr2[i] = arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]!=arr2[i]){
            count++;
        }
    }

    if(count/2==1){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;

>>>>>>> bf36b5b87c41ef9c8f1f279b27ea4242c03f220a
}