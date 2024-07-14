#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr , dep ; 

    for( int i =0 ; i < n ; i++){
        int x , y ; 
        cin >> x >> y ; 

        arr.push_back(x) ; 
        dep.push_back(y) ; 
    }

    sort(arr.begin() , arr.end());
    sort(dep.begin() , dep.end()); 

    int i = 0 , j = 0 , cnt = 0 , maxi = 0 ; 

    while (i < n )
    {
        if( arr[i] <= dep[j] ){
            cnt++;
            i++ ;
        }
        else{
            cnt-- ; 
            j++ ; 
        }

        maxi = max( maxi , cnt ) ; 
    }

    cout << maxi << endl ;

    return 0 ;

} 