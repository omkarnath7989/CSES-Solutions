#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x , y ; 

        cin >> x >> y ; 

        if( (x+y)%3 != 0 || x > 2*y || y > 2* x ) cout << "NO"<<endl ;
        else cout <<"YES"<<endl ;   
    }
    return 0 ;

} 