#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0)
    {
        cout << (y - x) / (a + b) << endl;
    }
    else
        cout << -1 << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}