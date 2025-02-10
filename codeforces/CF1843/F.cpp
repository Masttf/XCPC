#include<bits/stdc++.h>
#define int long long
using namespace std;

#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
	std::cout << std::endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int u,v,k;
};

struct nd{
	int lmax,rmax,sum,tmax,lmin,rmin,tmin;
};
void solve(){
	int n;cin>>n;
	vector<vector<int>>g(n+5);
	vector<int>w(n+5);
	int tot=1;
	w[1]=1;
	vector<node>q;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s[0]=='+'){
			int x,v;cin>>v>>x;
			tot++;
			g[tot].push_back(v);
			g[v].push_back(tot);
			w[tot]=x;
		}else{
			int u,v,k;cin>>u>>v>>k;
			q.push_back({u,v,k});
		}
	}
	auto up = [&](nd &rt,nd &l,nd &r)->void{
		rt.sum=l.sum+r.sum;
		rt.lmax=max(l.lmax,l.sum+r.lmax);
		rt.rmax=max(r.rmax,r.sum+l.rmax);
		rt.tmax=max({l.tmax,r.tmax,l.rmax+r.lmax});
		
		rt.lmin=min(l.lmin,l.sum+r.lmin);
		rt.rmin=min(r.rmin,r.sum+l.rmin);
		rt.tmin=min({l.tmin,r.tmin,l.rmin+r.lmin});
	};
	
	
	vector<int>dep(n+5);
	vector<vector<int>>f(25,vector<int>(n+5));
	vector<vector<nd>>val(25,vector<nd>(n+5));
	auto dfs = [&](auto self,int now,int father)->void{
		//dbg(now,"yes");
		dep[now]=dep[father]+1;
		f[0][now]=father;
		val[0][now].sum=w[father];
		if(w[father]==1){
			val[0][now].lmax=val[0][now].rmax=val[0][now].tmax=1;
			val[0][now].lmin=val[0][now].rmin=val[0][now].tmin=0;
		}else{
			val[0][now].lmax=val[0][now].rmax=val[0][now].tmax=0;
			val[0][now].lmin=val[0][now].rmin=val[0][now].tmin=-1;
		}
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
			up(val[i][now],val[i-1][now],val[i-1][f[i-1][now]]);
		}
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	//dbg("yes");
	auto work = [&](int u,int v)->nd{
		int a=u,b=v;
		if(dep[a]<dep[b]){
			swap(a,b);
			swap(u,v);
		}
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b])a= f[i][a];
		}
		if(a==b){
			nd res;
			res.sum=w[u];
			if(w[u]==1){
				res.lmax=res.rmax=res.tmax=1;
				res.lmin=res.rmin=res.tmin=0;
			}else{
				res.lmax=res.rmax=res.tmax=0;
				res.lmin=res.rmin=res.tmin=-1;
			}
			int d=dep[u]-dep[v];
			int temp=u;
			for(int i=20;i>=0;i--){
				if(d>>i&1){
					nd tp=res;
					up(res,tp,val[i][temp]);
					temp=f[i][temp];
				}
			}
			return res;
		}
		
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				a=f[i][a];
				b=f[i][b];
			}
		}
		
		nd res1;
		res1.sum=w[u];
		if(w[u]==1){
			res1.lmax=res1.rmax=res1.tmax=1;
			res1.lmin=res1.rmin=res1.tmin=0;
		}else{
			res1.lmax=res1.rmax=res1.tmax=0;
			res1.lmin=res1.rmin=res1.tmin=-1;
		}
		int d=dep[u]-dep[a];
		int temp=u;
		for(int i=20;i>=0;i--){
			if(d>>i&1){
				nd tp=res1;
				up(res1,tp,val[i][temp]);
				temp=f[i][temp];
			}
		}
		nd res2;
		res2.sum=w[v];
		if(w[v]==1){
			res2.lmax=res2.rmax=res2.tmax=1;
			res2.lmin=res2.rmin=res2.tmin=0;
		}else{
			res2.lmax=res2.rmax=res2.tmax=0;
			res2.lmin=res2.rmin=res2.tmin=-1;
		}
		d=dep[v]-dep[f[0][a]];
		temp=v;
		for(int i=20;i>=0;i--){
			if(d>>i&1){
				nd tp=res2;
				up(res2,tp,val[i][temp]);
				temp=f[i][temp];
			}
		}
		nd res;
		swap(res2.lmax,res2.rmax);
		swap(res2.lmin,res2.rmin);
		up(res,res1,res2);
		return res;
	};
	
	for(auto [u,v,k]:q){
		nd ans=work(u,v);
		//dbg(ans.tmax,ans.tmin);
		if((k>=0&&k<=ans.tmax)||(k<0&&k>=ans.tmin)){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}