#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

#define mod 1000000007 

int main()
{
    int n , x ; 

    cin >> n >> x ; 

    vector<int>arr(n) ; 

    vector<vector<int> >dp( n , vector<int>(x+1 , 0 )) ; 

    for( int i = 0 ; i < n ;i++)
    cin >> arr[i] ; 

    for( int i = 0 ; i <n ; i++){
        dp[i][0] = 1 ; 
    }

    for( int i = arr[0] ; i <= x ; i=i+arr[0])
       dp[0][i] = 1 ; 

    for( int i = 1 ; i < n ; i++){
        for( int j = 1 ; j <= x ; j++){

            int t = 0 ; 
            if( j >= arr[i]){
                t = dp[i][j-arr[i]] ; 
            }

            int nt = dp[i-1][j] ; 

            dp[i][j] = (t + nt)%mod ; 
        }
    }

    cout<< dp[n-1][x] ; 

    
    return 0 ;

} 