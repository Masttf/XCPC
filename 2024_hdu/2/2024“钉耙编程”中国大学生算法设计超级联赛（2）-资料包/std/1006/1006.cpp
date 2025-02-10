#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
struct E{
	int to,nx;
}edge[M<<1];
int tot,head[M];
void Addedge(int a,int b){
	edge[++tot].to=b;
	edge[tot].nx=head[a];
	head[a]=tot;
}
int A[M];
int fa[M];
long long gcd(long long a,long long b){
	if(!b)return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
struct node{
	long long a,b;
	bool operator <(const node &_)const{
		long long tmp=lcm(b,_.b);
		return a*(tmp/b)<_.a*(tmp/_.b);
	}
	node operator +(const node &_)const{
		node res;
		res.b=lcm(b,_.b);
		res.a=a*(res.b/b)+_.a*(res.b/_.b);
		if(res.a==0)return (node){0,1};
		long long g=gcd(res.a,res.b);
		res.a/=g;
		res.b/=g;
		return res;
	}
}dp[M];
void dfs(int now){
//	printf("now=%d\n",now);
	dp[now]=(node){0,1};
	for(int i=head[now];i;i=edge[i].nx){
		int nxt=edge[i].to;
		if(nxt==fa[now])continue;
		fa[nxt]=now;
		dfs(nxt);
		dp[now]=max(dp[now],dp[nxt]);
	}
	dp[now]=dp[now]+(node){15,A[now]};
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		tot=0;for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Addedge(a,b);
			Addedge(b,a);
		}
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		dfs(1);
		printf("%lld/%lld\n",dp[1].a,dp[1].b);
	}
	return 0;
}
