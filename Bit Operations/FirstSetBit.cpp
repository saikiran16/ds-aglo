using namespace std ;
#include<bits/stdc++.h>
int main()
{
    int n , i = 0 ;
    cout << "Enter A Number to get First Set Bit " <<endl;
    cin >> n ;
    int mask = 1;
    while((mask & n) == 0){
        i++;
        mask = mask << 1;
    }
    cout << "The First Set is at "<< i <<endl;
    return 0;
}