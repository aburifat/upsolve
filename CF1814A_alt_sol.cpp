#include <iostream>
using namespace std;
typedef long long ll;

// a*x0 + b*y0 = g = gcd(a,b)
ll exGcd(ll a, ll b, ll &x0, ll &y0)
{
    if (b == 0)
    {
        x0 = 1;
        y0 = 0;
        return a;
    }
    ll x, y;
    ll g = exGcd(b, a % b, x, y);
    x0 = y;
    y0 = x - y * (a / b);
    return g;
}

// a*x0 + b*y0 = c
bool haveSolution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    g = exGcd(abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= (c / g);
    y0 *= (c / g);
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a = 2, b, c;
        cin >> c >> b;
        ll x, y, g;
        bool ck = haveSolution(a, b, c, x, y, g);
        if (ck)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}