#include <algorithm> 
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;


int main()
{
   string str ; 
   cin >> str ; 

   vector<string> ds ; 

   sort( str.begin() , str.end());

   do{
    ds.push_back( str ) ; 
   }
   while (next_permutation(str.begin() , str.end()));
   
   cout<< ds.size() << endl ; 

   for( string x : ds )
   cout << x << endl ; 
   
} 