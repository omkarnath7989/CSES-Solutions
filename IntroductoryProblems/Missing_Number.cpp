#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n ;

    cin >> n ; 

    int arr[n-1] ; 

    for( int i = 0 ; i < n-1 ;i++ ){
        cin >> arr[i] ; 
    }

    int ans1 = 0  , ans2 = 0 ; 

    for( int i = 1 ; i <= n ;i++ )
    ans1 ^= i ; 

    for( int i = 0 ; i < n-1 ; i++)
    ans2 ^= arr[i] ; 

    cout << (ans1 ^ ans2)  << endl  ;

    return 0 ;  
} 