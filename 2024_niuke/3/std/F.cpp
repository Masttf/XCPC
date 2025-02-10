#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int maxn=1e7+3;
int n,m,k;
int inv[maxn],nf[maxn],f[maxn];
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void dec(int &x,int y){x-=y;if(x<0) x+=M;} 
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    nf[0]=f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int C(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int A(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[x-y]%M;
}
int nC(int x,int y){
    return 1ll*nf[x]*f[y]%M*f[x-y]%M;
}
int F(int x,int y){
    int p=x-y,q=y;
    return 1ll*A(n,p)*A(m,q)%M*(C(p+q-1,p-1)-C(p+q-1,p)+M)%M;
}
int main(){
    init();
    cin >> n >> m >> k;
    int ans=0;//(n-m+M)%M;
    int x=1,y=0,s=F(1,0),cof=1;
    while (x<=k){
        cof=1ll*cof*inv[n+m-x+1]%M;
        while (y<m&&(y+1)*2<x) y++,add(s,F(x,y));
        add(ans,1ll*s*cof%M); 
        x++; s=1ll*s*(n+m-x+1)%M;
        dec(s,1ll*(m-y)*F(x-1,y)%M);
    }
    cout << ans << endl;
}
