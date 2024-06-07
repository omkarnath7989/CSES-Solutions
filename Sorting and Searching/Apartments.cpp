#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int n , m , k  ; 

    cin >> n >> m >> k ; 

    vector<int>greed(n);
    vector<int>siz(m) ; 

    for( int i = 0 ; i < n ; i++)
    cin >> greed[i] ; 

    for( int i = 0 ; i < m ;i++)
    cin >> siz[i] ; 

    sort( greed.begin() , greed.end()) ; 
    sort( siz.begin() , siz.end()) ; 

    int i = 0 ; 
    int j = 0 ; 

    int ans = 0 ; 

    while( i < n && j < m ){

        if( abs(greed[i]-siz[j]) <= k ){
            ans++;
            i++;
            j++;
        }
        else if(siz[j] > greed[i]+k)
        i++;
        else
        j++;
        
    }

    cout << ans ; 

    return 0 ;

} 