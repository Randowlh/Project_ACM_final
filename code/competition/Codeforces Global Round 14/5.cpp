#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
// const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 500;
int n,mod;
int pre[maxn+100];int bit[maxn+100];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
void init(){
    pre[0]=1;
    for(int i=1;i<=maxn;i++)
        pre[i]=pre[i-1]*i%mod;
    bit[0]=1;
    for(int i=1;i<=maxn;i++)
       bit[i]=bit[i-1]*2%mod; 
}
int cc[maxn][maxn];
int C(int n,int m){
    if(n<m)
        return 0;
    if(cc[n][m])
        return cc[n][m];
    return cc[n][m]=pre[n]*powmod(pre[n-m],mod-2)%mod*powmod(pre[m],mod-2)%mod;
}
int dp[maxn][maxn];
void work()
{cin>>n>>mod;
    init();
    
    int ans=0;
    for(int i=1;i<=n;i++)
        dp[i][i]=bit[i-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            for(int k=1;i+k<=n;k++){
                dp[i+1+k][j+k]+=dp[i][j]*bit[k-1]%mod*C(j+k,k)%mod;
                dp[i+1+k][j+k]%=mod;
            }
    for(int i=1;i<=n;i++){
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}