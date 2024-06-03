#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;


void f( int n , int i , int d ){

    if( n==1 ){
        cout << i <<" " << d << endl ;
        return ; 
    }

    int des = 6 - i - d ; 
    f( n-1 , i , des ) ; 
    cout<< i << " " << d << endl ; 
    f( n-1 , des , d ) ; 
}

int main()
{
    int t;
    cin >> t;
    
    cout << ((1<<t) - 1) << endl ; 
    f( t , 1 , 3 ) ; 
    return 0 ;

} 