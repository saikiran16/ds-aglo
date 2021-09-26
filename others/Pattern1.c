// You are using GCC
#include<stdio.h>
int printUpper(int n){
    int i , j , l = (n*2)+1 ;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= l; j++ ){
            
            if( i >= j || (l-j + 1) <= i)
            printf("* ");
            else {
             printf("  ");   
            }
            
        }
        printf("\n");
    }
}
int printLower(int n){
    int i , j , l = (n*2)+1 ;
    for(i = n ; i > 0 ; i--)
    {
        for(j = l ; j > 0; j-- ){
            
            if( i >= j || (l-j + 1) <= i)
            printf("* ");
            else {
             printf("  ");   
            }
            
        }
        printf("\n");
    }
}
int main(){
    int n ;scanf("%d" , &n);
    printUpper(n) ;
    printLower(n);
    
    
}