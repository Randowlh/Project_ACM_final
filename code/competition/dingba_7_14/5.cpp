#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
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
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
#define pii(a,b) pair<a,b>
#define X first
#define Y second
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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int n,m,k;
int b[][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool date[1100][1100];
bool ck(int x,int y){
   if(x<=0 ||x>n)
      return false;
   if(y<=0||y>m)
      return false;
   return !date[x][y];
}
void work()
{
   cin>>n>>m>>k;
   int x,y;
   for(int i=1;i<=k;i++){
      cin>>x>>y;
      date[x][y]=1;
   }
   int ans=0;
   queue<pair<int,int>> q;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
         if(!date[i][j]){
            ans++;
            q.push(MP(i,j));
            date[i][j]=1;
            while(!q.empty()){
               auto t=q.front();
               q.pop();
               for(int i=0;i<4;i++){
                  int x=t.first+ b[i][0];
                  int y=t.second+b[i][1];
                  if(ck(x, y)){
                     date[x][y]=1;
                     q.push(MP(x,y));
                  }
               }
            }
         }
      }
   cout<<ans<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
// cin>>t;
while (t--)
{
work();
}
return 0;
}