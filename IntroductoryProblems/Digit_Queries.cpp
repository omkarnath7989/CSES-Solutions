#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n <= 9) {
            cout << n << endl;
            continue;
        }
        ll arr[19];
        arr[0] = 1;
        for (int i = 1; i < 19; i++)
            arr[i] = arr[i - 1] * 10;
        ll lb = 0;
        ll ub = 0;
        ll len = 1;
        for (int i = 1; i < 19; i++) {
            ub += (arr[i] - arr[i - 1]) * i;
            if (n <= ub) {
                len = i;
                break;
            }
            lb += (arr[i] - arr[i - 1]) * i;
        }
        ll l = arr[len - 1];
        ll r = arr[len] - 1;
        ll k = 0;
        ll num = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll s = lb + 1 + (mid - l + 1) * len;
            if (s <= n) {
                if( num )
                num = mid;
                k = s;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        string ans = to_string(num);
        cout << ans[n - k] << endl;
    }
    return 0;
}