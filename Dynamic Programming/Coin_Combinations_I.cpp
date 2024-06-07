#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007 ; 

int main()
{
    int n , x ; 

    cin >> n >> x ;

    vector<int>ds(n);

    for( int i = 0 ; i < n ;i++)
    cin >> ds[i]; 

    vector<int>dp(x+1 , 0 ) ; 

    dp[0] = 1 ; 

    for( int i  = 1 ; i <= x ; i++){
        for( int j = 0 ; j < n ; j++){
            if( ds[j] <= i){
                dp[i] = (dp[i]+dp[i-ds[j]])%mod; 
            }
        }
    }

    cout<< dp[x] ; 

    return 0 ;
} 