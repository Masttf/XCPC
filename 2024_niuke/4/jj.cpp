#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;
#define print(x) cout << #x << '=' << x << '\n';
#define printt(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << '\n';
#define int long long
const int N=2e5+5,mod=998244353;
int dp[N][40];
long long fac[N+5],inv[N+5];
long long qp(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1)ans*=a,ans%=mod;
        a=a*a;a%=mod;
        b>>=1;
    }
    return ans;
}
void init(void){
    fac[0]=fac[1]=1;
    for(int i=2;i<=N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N]=qp(fac[N],mod-2);
    for(int i=N-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(long long n,long long m){if(n<m||n<0||m<0)return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int a[40][40];
void solve(){
    init();
    int n,k;cin>>n>>k;
    string s;cin>>s;s=" "+s;
    for(int i=1;i<=30;i++){
        for(int j=i;j>=0;j--){
            a[i][j]=C(i,j);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0')continue;
        else{
            dp[i][0]=dp[i-1][0]+1;
            for(int d=1;d<=k;d++){
                dp[i][d]+=1;
                for(int _d=d;_d>=0;_d--){
                    dp[i][d]+=dp[i-1][_d]*a[d][_d]%mod;
                    dp[i][d]%=mod;
                }
            }

            if(s[i]=='?'){
                for(int d=k;d>=0;d--){
                    dp[i][d]*=qp(2,mod-2);
                    dp[i][d]%=mod;
                }
            }
        }
        ans+=dp[i][k];
        ans%=mod;
    }
    cout<<ans<<'\n';
}
signed main(void) {
    cin.tie(0)->sync_with_stdio(0);
//    int t;cin>>t;
//    while(t--)
    solve();
}