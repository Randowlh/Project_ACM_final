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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
vector<pair<int,int>> s;
vector<int>ss;
void work()
{
    int n;
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    int cnt=2;
    int flag=v[0]>v[1];
    for(int i=1;i<n-1;i++){
        if((v[i]>v[i+1])==flag){
            cnt++;
        }else{
            s.push_back(make_pair(cnt,flag));
            cnt=2;
            flag=(v[i]>v[i+1]);
        }
    }
    s.push_back(make_pair(cnt,flag));
    int mix=0;
    int ma=0;
    for(int i=0;i<s.size();i++){
        if(s[i].first>ma){
            ma=s[i].first;
            mix=i;
        }
    }
    int qc=-1;
    if(s[mix].second){
        if(mix>0){
            qc=mix-1;
        }
    }else {
        if(mix+1<n)
            qc=mix+1;
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i==qc)
            continue;
        ss.push_back(s[i].first);
    }
    sort(ss.begin(), ss.end());
    int ff=ss.size()==1?0:ss[1];
    if(qc!=-1){
        if(ss[0]>1&&ss[0]%2==1)
        if(max(ff-1,ss[0])<(ss[0]-1))
            ans++;
        ss.push_back(s[qc].first);
    }
    sort(ss.begin(), ss.end());
    ff=ss.size()==1?0:ss[1];
    for(int i=1;i<=ss[0];i++){
        if(i>1&&i%2==1){
            if(max(ff-1,ss[0]-i-1)<(i-1)){
                // cout<<"i="<<i<<endl;
                ans++;
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