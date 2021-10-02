struct MTT{
    static const int N=1<<20;
    struct cp{
        long double a,b;
        cp(){a=0,b=0;}
        cp(const long double &a,const long double &b):a(a),b(b){}
        cp operator+(const cp &t)const{return cp(a+t.a,b+t.b);}
        cp operator-(const cp &t)const{return cp(a-t.a,b-t.b);}
        cp operator*(const cp &t)const{return cp(a*t.a-b*t.b,a*t.b+b*t.a);}
        cp conj()const{return cp(a,-b);}
    };
    cp wn(int n,int f){
        static const long double pi=acos(-1.0);
        return cp(cos(pi/n),f*sin(pi/n));
    }
    int g[N];
    void dft(cp a[],int n,int f){
        for(int i=0;i<n;i++)if(i>g[i])swap(a[i],a[g[i]]);
        for(int i=1;i<n;i<<=1){
            cp w=wn(i,f);
            for(int j=0;j<n;j+=i<<1){
                cp e(1,0);
                for(int k=0;k<i;e=e*w,k++){
                    cp x=a[j+k],y=a[j+k+i]*e;
                    a[j+k]=x+y,a[j+k+i]=x-y;
                }
            }
        }
        if(f==-1){
            cp Inv(1.0/n,0);
            for(int i=0;i<n;i++)a[i]=a[i]*Inv;
        }
    }
    cp a[N],b[N],Aa[N],Ab[N],Ba[N],Bb[N];
    vector<ll> conv_mod(const vector<ll> &u,const vector<ll> &v,ll mod){ // 任意模数fft
        const int n=(int)u.size()-1,m=(int)v.size()-1,M=sqrt(mod)+1;
        const int k=32-__builtin_clz(n+m+1),s=1<<k;
        g[0]=0; for(int i=1;i<s;i++)g[i]=(g[i/2]/2)|((i&1)<<(k-1));
        for(int i=0;i<s;i++){
            a[i]=i<=n?cp(u[i]%mod%M,u[i]%mod/M):cp();
            b[i]=i<=m?cp(v[i]%mod%M,v[i]%mod/M):cp();
        }
        dft(a,s,1); dft(b,s,1);
        for(int i=0;i<s;i++){
            int j=(s-i)%s;
            cp t1=(a[i]+a[j].conj())*cp(0.5,0);
            cp t2=(a[i]-a[j].conj())*cp(0,-0.5);
            cp t3=(b[i]+b[j].conj())*cp(0.5,0);
            cp t4=(b[i]-b[j].conj())*cp(0,-0.5);
            Aa[i]=t1*t3,Ab[i]=t1*t4,Ba[i]=t2*t3,Bb[i]=t2*t4;
        }
        for(int i=0;i<s;i++){
            a[i]=Aa[i]+Ab[i]*cp(0,1);
            b[i]=Ba[i]+Bb[i]*cp(0,1);
        }
        dft(a,s,-1); dft(b,s,-1);
        vector<ll> ans;
        for(int i=0;i<n+m+1;i++){
            ll t1=llround(a[i].a)%mod;
            ll t2=llround(a[i].b)%mod;
            ll t3=llround(b[i].a)%mod;
            ll t4=llround(b[i].b)%mod;
            ans.push_back((t1+(t2+t3)*M%mod+t4*M*M)%mod);
        }
        return ans;
    }
}mtt;