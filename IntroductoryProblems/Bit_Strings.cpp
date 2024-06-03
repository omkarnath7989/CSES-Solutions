#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

ll f( int x){

    if( x==0 )
    return 1 ; 
    else if( x % 2 == 1){
        return ((2*f(x-1))%(1000000007)) ; 
    }
    else{
        return ((f(x/2)*f(x/2))%(1000000007)); 
    }
}

int main()
{
    int n ; 
    cin >> n ; 

    cout << f(n) ; 

    return 0 ;

} 