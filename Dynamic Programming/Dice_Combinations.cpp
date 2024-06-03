#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

ll f( int n , vector<int>&dp ){

    if( n <  0)
    return 0 ; 

    if( n == 0 )
    return 1 ; 

    if( dp[n] != -1 )
    return dp[n];

    ll sum = 0 ; 

    for( int i = 1 ; i <= 6 ; i++){
        sum += f( n - i , dp ) ;
        sum %= 1000000007 ; 
    }

    return dp[n] = sum ; 
}

int main()
{
    int t;
    cin >> t;

    vector<int>dp(t+1 , -1 ) ; 
   
    cout<<f(t , dp )<<endl ; 
    return 0 ;

} 