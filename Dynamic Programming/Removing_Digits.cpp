#include<iostream>
#include<vector>
#include <climits>
typedef long long ll;
using namespace std;

int main()
{
    int n ; 
    cin >> n ; 

    if( n <= 9 ){
        cout << 1 << endl ; 
        return 0 ; 
    }

    vector<int>dp( n+1 , 1e6 ) ; 

    for( int i = 1 ; i <= 9 ; i++  )
    dp[i] = 1 ; 

    for( int i = 10 ; i <= n ; i++){

        int k  = i ; 
        int maxi = INT_MAX ; 
        while ( k > 0 )
        {
            int y = k % 10 ; 
            k = k/10 ; 
            maxi = min( maxi , dp[i-y]) ; 
        }

        dp[i] = 1 + maxi ; 
    }

    cout << dp[n] << endl ; 

    return 0 ;

} 