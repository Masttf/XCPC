#include <bits/stdc++.h>

#define Max 100005

using namespace std;

const int mod=1e9+7;

int T,n,m,rt,ans,h[Max],p[Max],deg[Max];
vector<int>E[Max];

inline int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ans;
}

inline long long calc(int x){
	int w=1000000000;
	if(m<30)w=qpow(2,m)-1;
	return 1ll*(h[x]-1)*w+p[x];
}

inline void dfs(int u,int fa){
	if(calc(u)>calc(rt))rt=u;
	for(int v:E[u]){
		if(v==fa)continue;
		h[v]=h[u]+deg[v]-1;
		p[v]=p[u]+1;
		dfs(v,u);
	}
	return;
}

int main(){
	// freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)E[i].clear(),deg[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		rt=1;
		p[1]=1;
		h[1]=deg[1]-1;
		dfs(1,1);
		p[rt]=1;
		h[rt]=deg[rt]-1;
		dfs(rt,rt);
//		cout<<h[rt]<<" "<<p[rt]<<endl;
		cout<<(1ll*h[rt]*(qpow(2,m)-1)%mod+p[rt])%mod<<endl;
	}
	return 0;
}
