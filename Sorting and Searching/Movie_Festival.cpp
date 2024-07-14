#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

bool mycomp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> ds;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ds.push_back({x, y});
    }

    sort(ds.begin(), ds.end(), mycomp);
    
    int cnt = 1;
    int prev = 0;

    for (int i = 1; i < n; i++) {
        if (ds[prev].second <= ds[i].first) {
            cnt++;
            prev = i;
        }
    }

    cout << cnt << endl;

    return 0;
}
