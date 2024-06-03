#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll f( int ind , vector<int> ds , long long k , long long cs , int n , long long sum  ){

    if( cs > k ){
        return abs(2*cs - sum ) ; 
    }
    if( ind == n ){
        return abs(2*cs - sum ) ; 
    }

    ll t = f( ind+1 , ds , k , cs+ds[ind] , n , sum  ) ; 

    ll nt = f( ind+1 , ds , k , cs , n , sum  ) ; 

    return min( t , nt ) ; 
}

int main()
{
    int n;
    cin >> n;

    vector<int> ds( n ) ; 

    long long sum = 0; 

    

    for( int i = 0 ; i < n ; i++){
         cin >> ds[i] ;  

         sum += ds[i] ; 
    }

    cout << f( 0 ,  ds  , sum/2 , 0 , n  , sum ) ; 

   return 0 ; 

} 