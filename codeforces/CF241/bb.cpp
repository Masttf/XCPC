#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const int mod=1e9+7;
const int inv2=5e8+4;
int n,a[maxn];
long long ans,k;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int ch[maxn*20][2],val[maxn*20],cnt;
inline void insert(int x){
	int u=0;
	for(int i=30;i>=0;i--){
		int t=((1<<i)&x)!=0;
		if(!ch[u][t])ch[u][t]=++cnt;
		u=ch[u][t];val[u]++;
	}
}
inline long long check(int x){
	long long tot=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=30;j>=0;j--){
			int t1=((1<<j)&a[i])!=0;
			int t2=((1<<j)&x)!=0;
			if(!t2)tot+=val[ch[u][t1^1]],u=ch[u][t1];
			else u=ch[u][t1^1];
			if(!u)break;
		}
		tot+=val[u];
	}
	return tot/2;
}
int tr[maxn*20][35];
inline void pre(int x,int dep,int z){
	if(x==0)return;
	if(dep==0){
		for(int i=0;i<=30;i++)
			if((1<<i)&z)tr[x][i]=val[x];
		return;
	}
	pre(ch[x][0],dep-1,z);
	pre(ch[x][1],dep-1,z|(1<<dep-1));
	for(int i=0;i<=30;i++)
		tr[x][i]=tr[ch[x][0]][i]+tr[ch[x][1]][i];
}
inline void solve(int kth){
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=30;j>=0;j--){
			int t1=((1<<j)&a[i])!=0;
			int t2=((1<<j)&kth)!=0;
			if(!t2){
				int t=ch[u][t1^1];
				for(int k=0;k<=30;k++){
					int t3=((1<<k)&a[i])!=0;
					if(t3)ans=(ans+1ll*(val[t]-tr[t][k])*(1ll<<k))%mod;
					else ans=(ans+1ll*tr[t][k]*(1ll<<k))%mod;
				}u=ch[u][t1];
				//printf("%lld %lld %lld\n",i,j,ans);
			}else u=ch[u][t1^1];
			if(u==0)break;
		}
		ans=(ans+1ll*val[u]*kth)%mod;
		//printf("%lld %lld\n",i,ans);
	}
}
int main(){
	n=read();scanf("%lld",&k);
	if(!k)return puts("0"),0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		insert(a[i]);
	int l=0,r=1<<30,kth=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)>=k)kth=mid,l=mid+1;
		else r=mid-1;
	}
	pre(ch[0][0],30,0);
	pre(ch[0][1],30,1<<30);
	solve(kth);
	if(n == 51)printf("%lld\n",kth);
	ans=ans*inv2%mod;
	ans=((ans-1ll*(check(kth)-k)*kth%mod)%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}