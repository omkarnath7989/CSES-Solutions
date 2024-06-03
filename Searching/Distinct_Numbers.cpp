#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int x ; 
    set<int>ds; 

    for(int i =0 ; i < t ; i++){
        cin>>x ; 
        ds.insert(x) ;
    }

    cout << ds.size() ; 
    return 0 ;

} 