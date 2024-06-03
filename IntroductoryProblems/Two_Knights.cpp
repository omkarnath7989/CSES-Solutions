#include<iostream>
#include<vector>
using namespace std;

long long f( int n ){

    if( n == 1 )
    return 0 ; 
    else if( n == 2 )
    return 6 ; 
    else{

        long long k = n*1ll*n*1ll ; 

        long long ans = k * ( k- 1 ) / 2 ; 

        long long dif = 4*(n-1)*(n-2) ; 

        return ( ans - dif ) ; 
    }
}

int main()
{
    long long int n ; 

    cin >> n; 

    for( int i = 1 ; i <= n ; i++){
        cout << f(i)<<endl ; 
    }
    return 0 ;

} 