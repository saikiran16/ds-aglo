// You are using GCC
#include<stdio.h>
int printUpper(int n){
    int i , j , l = 2-n-1 ;
    for(i = 1 ; i <= n ; i++ ){
        /*for(j = 1 ; j <= (n-i) ; j++){
            printf(" ");
        }
        for(j = 1 ; j <= 2*i-1 ; j++){
            printf("*");
        }*/
        for(j = 1 ; j<=(n+i-1) ; j++){
            if(j <= (n-i)) printf(" ");
            else printf("*");
        }
        printf("\n");
        
    }
    
}
int printLower(int n ){
    int i , j ;
    for(i = 1 ; i <= 3 ; i++){
        for(j = 1 ; j <= 2*n-1 ; j++){
            if(j <= 3 || j > (2*n-4))
            printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
}
#include<stdio.h>
int main(){
    int n ;
    scanf("%d" , &n);
    printUpper(n) ;
    printLower(n);
}