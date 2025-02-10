#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=35,mod=998244353;
int f[maxn],u[maxn],v[maxn],p[maxn];
int ans=0;
int n,m,k;
int find(int x){
	if(f[x]==x)return x;
	else return find(f[x]);
}
void dfs(int i,int c){
	if(i==m+1){
		int d=n-c;
		if(d%2==0)ans=(ans+p[c])%mod;
		else ans=((ans-p[c])%mod+mod)%mod;
		return ;
	}
	int fa=find(u[i]);
	int fb=find(v[i]);
	if(fa==fb)return ;
	dfs(i+1,c);
	f[fb]=fa;
	dfs(i+1,c-1);
	f[fb]=fb;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(NULL));
	p[0]=1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*k%mod;
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		u[i]=x;
		v[i]=y;
		if(rand()&1)swap(u[i],v[i]);
	}
	if(m>0){
		for(int i=1;i<=1000;i++){
			int x=rand()%m+1;
			int y=rand()%m+1;
			while(y!=x){
				y=rand()%m+1;
			}
			swap(u[x],u[y]);
			swap(v[x],v[y]);
		}
	}
	
	dfs(1,n);
	cout<<ans;
	return 0;
}
