#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ct = n / k;
        ll res = n - (ct * k);
        if (res % 2 != 0 && ct > 0)
            res += k;
        if (res % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}