#include <vector>
#include <iostream>
using namespace std;

int bc( int n , int pow ){

    return ( n & (1<<pow)) != 0 ; 
}

int main() {
    int n;
    cin >> n;
    

    for( int i = 0 ; i < (1<<n) ; i++){

        cout<< bc(i,n-1) ; 

        for( int j = n-2 ; j >= 0 ; j--){
            cout << (bc(i , j ) ^ bc( i , j+1 )) ; 
        }

        cout << endl ; 
    }

    return 0;
}