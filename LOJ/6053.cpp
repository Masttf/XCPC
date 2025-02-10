#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAX 222222
#define MOD 1000000007
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
ll n,Sqr,w[MAX];
ll pri[MAX],id1[MAX],id2[MAX],h[MAX],g[MAX],m;
bool zs[MAX];
int tot,sp[MAX];
void pre(int n)
{
	zs[1]=true;
	for(int i=2;i<=n;++i)
	{
		if(!zs[i])pri[++tot]=i,sp[tot]=(sp[tot-1]+i)%MOD;
		for(int j=1;j<=tot&&i*pri[j]<=n;++j)
		{
			zs[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
}
int S(ll x,int y)
{
	// cout << x << ' ' << y << ' ' << tot << '\n';
	if(x<=1||pri[y]>x)return 0;
	int k=(x<=Sqr)?id1[x]:id2[n/x],ret=(g[k]-sp[y-1]-h[k]+y-1)%MOD;
	if(y==1)ret+=2;
	for(int i=y;i<=tot&&1ll*pri[i]*pri[i]<=x;++i)
	{
		ll t1=pri[i],t2=1ll*pri[i]*pri[i];
		for(int e=1;t2<=x;++e,t1=t2,t2*=pri[i])
			(ret+=((1ll*S(x/t1,i+1)*(pri[i]^e)%MOD+(pri[i]^(e+1))%MOD)))%=MOD;
	}
	// cout <<"res\n";
	// cout << x <<' ' << y << ' ' << ret << endl;
	return ret;
}
int main()
{
	scanf("%lld",&n);Sqr=sqrt(n);
	pre(Sqr);
	for(ll i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);w[++m]=n/i;
		h[m]=(w[m]-1)%MOD;
		g[m]=(w[m]%MOD)*((w[m]+1)%MOD)%MOD;
		if(g[m]&1)g[m]=g[m]+MOD;g[m]/=2;g[m]--;
		if(w[m]<=Sqr)id1[w[m]]=m;
		else id2[j]=m;
		dbg(m);
		dbg(h[m]);
		dbg(g[m]);
	}
	cout << g[1] << ' ' << h[1] << endl;
	for(int j=1;j<=tot;++j)
		for(int i=1;i<=m&&pri[j]*pri[j]<=w[i];++i)
		{
			int k=(w[i]/pri[j]<=Sqr)?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
			(g[i]-=1ll*pri[j]*(g[k]-sp[j-1])%MOD)%=MOD;
			(h[i]-=h[k]-j+1)%=MOD;
		}
	int ans=S(n,1)+1;
	printf("%d\n",(ans+MOD)%MOD);
	return 0;
}