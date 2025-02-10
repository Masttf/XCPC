#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>vis(n+1);
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		vis[x]=1;
	}
	vector g(n+1,vector<int>());
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int s,t;cin>>s>>t;
	vis[t]=1;
	vector<int>f(n+1);
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto mg = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
	};
	auto check = [&](int x)->bool{
		queue<int>q;
		vector<int>d(n+1),vs(n+1);
		for(int i=1;i<=n;i++){
			f[i]=i;
			if(vis[i]){
				q.push(i);
				vs[i]=1;
			}
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(!vs[v]){
					vs[v]=1;
					d[v]=d[u]+1;
					mg(v,u);
					if(find(find,s)==find(find,t))return true;
					if(d[v]<x)q.push(v);
				}else{
					if(d[v]+d[u]+1<=x){
						mg(v,u);
						if(find(find,s)==find(find,t))return true;
					}
				}
			}
		}
		return false;
	};
	int ans=-1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
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