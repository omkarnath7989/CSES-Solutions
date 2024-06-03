#include<iostream>
#include<vector>
#include<unordered_map>
typedef long long ll;
using namespace std;

int main()
{
    string str ; 
    cin >> str ; 

    int n = str.size() ; 

    vector<int>v(26,0); 

    vector<char>ans(n) ; 

    int ind = -1  ; 

    for( int i = 0 ; i < n ; i++)
    v[str[i]-'A']++;

    int cnt = 1 ; 

    for( int i = 0 ; i < 26 ; i++)
    if(v[i] % 2 == 1){
        cnt-- ;
        ind = i ; 
    }
     

    if( cnt < 0 )
    cout<<"NO SOLUTION" ;
    else if(ind != -1){
        v[ind]--; 

        for( int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < v[i]/2 ; j++)
            cout<<(char)(i+'A') ; 
        }
        cout<<(char)(ind+'A') ; 
        for( int i = 25 ; i >= 0 ; i--){
            for(int j = 0 ; j < v[i]/2 ; j++)
            cout<<(char)(i+'A') ; 
        } 
    }
    else{
        for( int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < v[i]/2 ; j++)
            cout<<(char)(i+'A') ; 
        }
        for( int i = 25 ; i >= 0 ; i--){
            for(int j = 0 ; j < v[i]/2 ; j++)
            cout<<(char)(i+'A') ; 
        } 
    }

    
    return 0 ;

} 