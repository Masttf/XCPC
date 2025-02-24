#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define ll long long
#define rll register long long
const int N=1e6+10;
const int p=998244353;
const int inv=p+1>>1;
ll dp0[70][2],dp1[70][2];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(dp0,0,sizeof(dp0));
        memset(dp1,0,sizeof(dp1));
        for(int j=0;j<=60;j++)dp0[j][0]=dp1[j][0]=1;
        ll xsum=0;
        for(int i=1;i<=n;i++){
            ll x;
            scanf("%lld",&x);
            x++;xsum^=x;
            ll now=0,s=0;
            for(int j=0;j<=60;j++){
                ll d0=dp0[j][0],d1=dp0[j][1];
                dp0[j][x>>j&1]=d0*s%p;
                dp0[j][~x>>j&1]=d1*s%p;
                d0=dp1[j][0],d1=dp1[j][1];
                dp1[j][x>>j&1]=d0*s%p;
                dp1[j][~x>>j&1]=d1*s%p;
                if(x>>j&1){
                    s+=1ll<<j;s%=p;
                    dp1[j][0]=(dp1[j][0]+(1ll<<j)%p*d0)%p;
                    dp1[j][1]=(dp1[j][1]+(1ll<<j)%p*d1)%p;
                }
            }
        }
        while(m--){
            ll L,R;
            scanf("%lld%lld",&L,&R);
            ll res=0,tem=xsum;
            for(ll s=0,pw=1;s<=60;s++,pw=pw*inv%p){
                ll t=xsum;
                xsum>>=s+1;xsum<<=s+1;
                ll len1=min(R,xsum|((1ll<<s)-1))-max(L,xsum)+1;
                ll len2=min(R,xsum|((1ll<<s+1)-1))-max(L,xsum|(1ll<<s))+1;
                len1%=p;len2%=p;
                if(len1>0)res+=(dp1[s][0]-dp0[s][0])*len1%p*pw%p;
                if(len2>0)res+=(dp1[s][1]-dp0[s][1])*len2%p*pw%p;
                xsum=t;
            }
            printf("%lld\n",(res%p+p)%p);
            xsum=tem;
        }
    }
    return 0;
}
