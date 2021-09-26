using namespace std ;
#include<bits/stdc++.h>
int main(){

    int n , lRange , rRange ;
    cout << "Enter a number" << endl;
    cin >> n ;
    cin >> lRange  ;
    cin >> rRange ;
    int finalResult = n ;
    int mask = (1 << (lRange-1)) ;
    for(int i = lRange ; i <=rRange ; i++){
        if ((n & mask)  != 0 ){ 
            finalResult = finalResult - mask;
        }
        else{
               finalResult = finalResult + mask;   
        }
        mask = mask << 1;
    }
    cout << "Final Result " << finalResult <<endl;
    

    return 0;
}