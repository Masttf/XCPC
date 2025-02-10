#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x( x < 0 ? x % mod + mod : x % mod ) {} 
    //ModInt(long long x) : x(x % mod) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }         
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }           
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
    friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}                       
                
};
using mint =ModInt<1000000007>;
constexpr int mod=1e9+7;
mint qmi(mint a,int b){
    mint res=1;
    while(b){
        if(b&1)res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}
mint C(int n,int m){
    if(n<m||m<0)return 0;
    int mx=max(n,m);
    vector<mint>f(mx+1),inv(mx+1);
    f[0]=inv[0]=1;
    for(int i=1;i<=mx;i++){
        f[i]=f[i-1]*i;
        inv[i]=qmi(f[i],mod-2);
    }
    return f[n]*inv[m]*inv[n-m];
}
void solve(){
    int x,k;cin>>x>>k;
    mint ans=0;
    auto get = [&](int d)->void{
        int lcm=x/d-1;
        if(lcm==0)return ;
        vector<int>p,cnt;
        for(int i=2;i*i<=lcm;i++){
            if(lcm%i==0){
                cnt.push_back(0);
                p.push_back(i);
                while(lcm%i==0){
                    cnt.back()++;
                    lcm/=i;
                }
            }
        }
        if(lcm>1){
            p.push_back(lcm);
            cnt.push_back(1);
        }
        int m=p.size();
        for(int i=0;i<(1<<m);i++){
            for(int j=0;j<(1<<m);j++){
                int res=1;
                int eocf=1;
                for(int k=0;k<m;k++){
                    int tot=cnt[k]+1;
                    if(i>>k&1){
                        tot--;
                        eocf*=-1;
                    }
                    if(j>>k&1){
                        tot--;
                        eocf*=-1;
                    }
                    res*=tot;
                }
                ans+=C(res,k)*eocf;
            }
        }
    };
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            get(i);
            if(i*i!=x)get(x/i);
        }
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}