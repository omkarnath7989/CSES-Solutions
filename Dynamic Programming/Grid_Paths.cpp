#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

ll f( int i , int j , vector<string>&ds , vector<vector<int> >&dp ){

    if( i < 0 || j < 0 || ds[i][j] =='*' )
    return 0 ; 

    if( i == 0 && j == 0 )
    return 1 ; 

    if( dp[i][j] != -1)
    return dp[i][j] ; 

    return dp[i][j] = (f(i-1 , j , ds , dp ) + f(i , j-1 , ds , dp ))%1000000007; 
}


int main()
{
    int n ; 
    cin >> n ; 

    vector<string>ds ; 

    for( int i = 0 ; i < n ; i++){
        string s ; 
        cin >> s ; 
        ds.push_back(s); 
    }

    vector<vector<int> >dp( n , vector<int>(n , -1)) ; 

    cout << f( n-1 , n-1 , ds , dp ) ; 

    return 0 ;

} 