#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;


int main()
{
    int n , x ; 

    cin >> n >> x ; 

    vector<int>ds(n) ; 

    vector<int>dp( x+1 , 1e9) ;

    for( int i = 0 ; i < n ; i++)
    cin >> ds[i] ; 

   dp[0] = 0 ; 

   for( int i = 1 ; i <= x ; i++ ){
    for( int j = 0 ; j < n ; j++){
        if( ds[j] <= i){
            dp[i] = min(dp[i] , 1+ dp[(i-ds[j])]) ; 
        }
    }
   }

   if( dp[x] >= 1e9)
   cout << -1 ;
   else
   cout << dp[x] ; 

   return 0 ; 
     
    

} 