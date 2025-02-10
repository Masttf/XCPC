#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector a(m+1,vector<int>());
	vector<int> val(m+1);
	for(int i=1;i<=m;i++){
		cin>>val[i];
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;cin>>x;
			if(x==-1)x=n+1;
			a[i].push_back(x);
		}
	}

	auto check = [&]()->bool{
		vector<int>f(n+m+5);
		for(int i=0;i<=n+m+1;i++)f[i]=i;
		auto find =[&](auto self,int x)->int{
			return f[x]==x?x:f[x]=self(self,f[x]);
		};
		auto merge = [&](int a,int b)->void{
			int fa=find(find,a);
			int fb=find(find,b);
			if(fa==fb)return ;
			f[fa]=fb;
		};
		for(int i=1;i<=m;i++){
			for(auto x:a[i]){
				merge(i+n+1,x);
			}
		}
		int sz=0;
		for(int i=1;i<=n+m+1;i++){
			if(find(find,i)==i)sz++;
		}
		return sz==1;
	};
	if(!check()){
		cout<<0<<'\n';
		return ;
	}
	vector<int>cnt(n+5);
	vector<node>e;
	vector g(n+5,vector<int>());
	auto add = [&](int u,int v,int w)->void{
		g[u].push_back(e.size());
		e.push_back({v,w});
		g[v].push_back(e.size());
		e.push_back({u,0});
	};
	vector<int>h(n+5);
	vector<int>cur(n+5);
	int s=0,t=n+2;
	auto bfs = [&]()->bool{
		h.assign(n+5,-1);
		h[s]=0;
		queue<int>q;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto i:g[u]){
				auto [v,w]=e[i];
				if(h[v]==-1&&w>0){
					h[v]=h[u]+1;
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	};

	auto dfs = [&](auto self,int u,int f)->int{
		if(u==t)return f;
		int res=f;
		for(int &i=cur[u];i<(int)g[u].size();i++){
			int j=g[u][i];
			auto [v,w]=e[j];
			if(h[v]==h[u]+1&&w>0){
				int d=self(self,v,min(w,res));
				cnt[u]-=d;
				cnt[v]+=d;
				e[j].w-=d;
				e[j^1].w+=d;
				res-=d;
				if(!res)return f;
			}
		}
		return f-res;
	};

	int ans=0;
	auto dinic = [&]()->void{
		while(bfs()){
			cur.assign(n+5,0);
			ans+=dfs(dfs,s,k);
		}
	};
	for(int i=1;i<=m;i++){
		for(auto &x:a[i])x++;
	}
	auto link = [&](int time)->void{
		e=vector<node>();
		g=vector(n+5,vector<int>());
		for(int i=1;i<=n+1;i++){
			add(0,i,cnt[i]);
		}
		for(int i=1;i<=m;i++){
			int u=a[time]
		}
	};
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}