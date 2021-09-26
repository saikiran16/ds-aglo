// You are using GCC
#include<stdio.h>

void printUpper(int n){
    int i , j ,l = 2*n+1 ;
    for(i = n ; i >= 1 ; i--){
        for(j = l ; j >=1 ;j--){
            if(j <= i || (l-j+1) <=i)
            printf("* ");
            else 
            printf("  ");
        }printf("\n");
    }
}
void printLower(int n){
    int i , j ,l = 2*n+1 ;
    for(i = 1 ; i <= n ; i++){
        for(j = 1 ; j <= l ;j++){
            if(j <= i || (l-j+1) <=i)
            printf("* ");
            else 
            printf("  ");
        }printf("\n");
    }
}
#include<stdio.h>
int main(){
    int n ;
    scanf("%d" ,&n);
    printUpper(n);
    printLower(n);

    
    return 0 ;
}