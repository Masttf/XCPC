#include <bits/stdc++.h>
#define IL inline
#define LL long long
#define int long long
#define eb emplace_back
#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
using namespace std;
constexpr int P = 998244353;
constexpr int R = 3;

IL void qm(int &x) {
    x += x >> 31 & P;
}

IL int qpow(int b, int k) {
    int r = 1;

    for (; k; k >>= 1, b = (LL)b * b % P)
        if (k & 1)
            r = (LL)r * b % P;

    return r;
}

namespace ntt {
    int n, lg, rt[1 << 23];
    
    void init(int z) {
        n = 1, lg = 0;
    
        while (n < z) {
            n <<= 1;
            ++lg;
        }
    
        int w = qpow(R, (P - 1) / n);
        rt[0] = 1;
        L(i, 1, n - 1) {
            rt[i] = (LL)rt[i - 1] * w % P;
        }
    }
    
    void dif(int *a) {
        for (int l = n; l > 1; l >>= 1) {
            int m = l >> 1;
    
            for (int i = 0; i < n; i += l) {
                for (int j = 0; j < m; j++) {
                    int t = a[i + j] + a[i + j + m];
                    a[i + j + m] = (LL)rt[n / l * j] * (a[i + j] - a[i + j + m] + P) % P;
                    qm(a[i + j] = t - P);
                }
            }
        }
    }
    
    void dit(int *a) {
        for (int l = 2; l <= n; l <<= 1) {
            int m = l >> 1;
    
            for (int i = 0; i < n; i += l) {
                for (int j = 0; j < m; j++) {
                    int t = (LL)rt[n / l * j] * a[i + j + m] % P;
                    qm(a[i + j + m] = a[i + j] - t);
                    qm(a[i + j] += t - P);
                }
            }
        }
    
        reverse(a + 1, a + n);
        int iv = P - (P - 1) / n;
        L(i, 0, n - 1) {
            a[i] = (LL)a[i] * iv % P;
        }
    }
}
const int N = (1<<23);
int n, a[N], b[N];
int e[1100000];
const int M=10000100;
int G[M];
int inv[M];
long long T;
signed main() {
//        freopen("10.in","r",stdin); 
//        freopen("10.out","w",stdout); 
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> T;
    L(i, 1, n){
        int x; cin >> x;
        a[x] ++;
        b[1000000-x] ++;
        e[x] ++;
    }
    ntt::init(2000000 + 3);
    ntt::dif(a);
    ntt::dif(b);
    L(i, 0, ntt::n - 1) {
        a[i] = (LL)a[i] * b[i] % P;
    }
    ntt::dit(a);
    a[1000000]=0; int ans=0;
    for(int i=0;i<=1000000;i++) a[1000000]=(a[1000000]+1ll*e[i]*(e[i]-1)/2)%P;
    int c=n-2,d=(1ll*n*(n-1)/2-c-c)%P;
    int s=qpow(c,T);
    d=1ll*d*qpow(c,P-2)%P,c=1;
    G[0]=s;
    G[1]=1ll*s*T%P*d%P;
    G[2]=(1ll*s*T%P+1ll*s%P*(1ll*(T*(T-1)/2)%P)%P*d%P*d)%P;
    inv[0]=1;
    for(int i=1;i<M;i++){
        inv[i]=1ll*inv[i-1]*i%P;
    }
    inv[M-1]=qpow(inv[M-1],P-2);
    for (int i=M-1;i>=1;i--) {
        int tmp=inv[i];
        inv[i]=1ll*inv[i]*inv[i-1]%P;
        inv[i-1]=1ll*tmp*i%P;
    }
    for(int i=3;i<=T;i++){
        long long a=1ll*d*G[i-1]%P*T%P;
        long long b=2ll*T*G[i-2]%P;
        long long c=1ll*d*(i-1)%P*G[i-1]%P;
        long long d=1ll*(i-2)*G[i-2]%P;
        c=P-c;
        d=P-d;
        a=(a+b+c+d)%P;
        G[i]=1ll*a*inv[i]%P;
    }
    for(int i=0;i<=999999;i++) 
        if (T>=i) ans=(ans+1ll*a[1000000-i]*G[T-i])%P;
    cout<<1ll*ans*qpow(qpow((n*(n-1)/2)%P,P-2),T)%P<<endl;
}
