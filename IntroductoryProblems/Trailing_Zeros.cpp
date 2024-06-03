#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;

    int ans = 0 ; 
    
    while(t > 0){
        t/=5; 
        ans += t ; 
    } 

    cout << ans ; 


    return 0 ;

} 