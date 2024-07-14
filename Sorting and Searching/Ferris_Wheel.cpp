#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int n , w ; 

    cin >> n >> w ; 

    vector<int>v(n) ; 

    for( int i =0 ; i <n ; i++)
    cin >> v[i] ; 

    sort( v.begin() , v.end()) ; 

    int i = 0 , j = n-1 ; 

    ll ans = 0 ; 

    while( i < j ){

        if( v[i] + v[j] > w ){
            j--;
            ans++; 
        }
        else{
            i++;
            j--; 
            ans++ ; 
        }
    }

    if( i == j )
    ans++; 

    cout << ans ; 

    return 0 ;

} 