#include<iostream>
#include<vector>
#include<set>
typedef long long ll;
using namespace std;

int main()
{
    int n , m ; 
    cin >> n >> m ; 

    multiset<ll>prices; 

    for( int i = 0 ; i < n ; i++){
        int x ; 
        cin >> x ; 
        prices.insert(x); 
    }

    for( int i = 0 ; i < m ; i++){

        int x ; 
        cin >> x ; 

        auto it = prices.upper_bound(x) ; 

        if( it == prices.begin()){
            cout<<-1<<endl; 
        }
        else{
            cout<< *(--it) << endl ; 
            prices.erase(it); 
        }
    }
    return 0 ;

} 