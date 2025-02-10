#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=i+b[i];
	}
	vector<vector<pair<int,int>>>g(n*10);
	int tot=0;
	int py=4*n;
	map<int,int>m;
	auto bulid = [&](auto self,int l,int r,int p)->void{
		//dbg(l,r,p);
		if(l==r){
			m[p]=l;
			g[p].push_back({py+b[l]+1,0});
			g[py+b[l]+1].push_back({p,0});
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		g[p].push_back({p<<1,0});
		g[p].push_back({p<<1|1,0});
		return ;
	};
	auto link = [&](auto self,int l,int r,int x,int y,int k,int p)->void{
		if(x<=l&&r<=y){
			g[py+k+1].push_back({p,1});
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,p<<1|1);
		return ;
	};
	bulid(bulid,0,n,1);
	for(int i=1;i<=n;i++){
		int l=i-a[i];
		int r=i;
		link(link,0,n,l,r,i,1);
	}
	vector<int>pre(10*n);
	auto dij = [&]()->int{
		vector<int>d(n*10,Max);
		vector<int>vis(n*10);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		d[py+n+1]=0;
		q.push({d[py+n+1],py+n+1});
		while(!q.empty()){
			auto [ww,u]=q.top();
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto [v,w]:g[u]){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					pre[v]=u;
					q.push({d[v],v});
				}
			}
		}
		return d[py+1];
	};
	int ans=dij();
	if(ans==Max)cout<<-1<<'\n';
	else{
		cout<<ans<<'\n';
		vector<int>res;
		int now=py+1;
		while(now!=py+n+1){
			if(m.count(now))res.push_back(m[now]);
			now=pre[now];
			//dbg(now);
		}
		reverse(res.begin(),res.end());
		for(auto x:res)cout<<x<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}