#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string str ;

    cin >> str ;

    if( str.size() == 1 ){
        cout << 1 << endl ; 
        return 0 ; 
    }

    int cnt = 1  , maxi = 0 ; 

    for( int i = 1 ; i < str.size() ; i++ ){
        if( str[i] == str[i-1]){
            cnt++ ; 
        }else{
            cnt= 1 ; 
        }

        maxi = max( maxi , cnt ) ; 
    }
    cout << maxi << endl ; 

    return 0 ;

} 