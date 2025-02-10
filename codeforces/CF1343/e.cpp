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
void solve(){
	int n,m,a,b,c;cin>>n>>m>>a>>b>>c;

	vector<int>p(m+1);
	for(int i=1;i<=m;i++)cin>>p[i];
	sort(p.begin()+1,p.end());
	vector<int>pre(m+1);
	for(int i=1;i<=m;i++)pre[i]=pre[i-1]+p[i];

	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	auto bfs = [&](auto x,vector<int>&d)->void{
		queue<int>q;
		d[x]=1;
		q.push(x);
		while(!q.empty()){
			int rt=q.front();q.pop();
			for(auto v:g[rt]){
				if(d[v])continue;
				d[v]=d[rt]+1;
				q.push(v);
			}
		}
		return ;
	};

	vector<int>da(n+1);
	vector<int>db(n+1);
	vector<int>dc(n+1);
	bfs(a,da);
	bfs(b,db);
	bfs(c,dc);
	//for(int i=1;i<=n;i++)cout<<db[i]<<" \n"[i==n];

	int ans=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		int len=da[i]+db[i]+dc[i]-3;
		//cout<<i<<' '<<len<<endl;
		if(len>m)continue;
		ans=min(ans,pre[len]+pre[db[i]-1]);
		//int val=pre[len]+pre[db[i]];
		//dbg(i,ans,val);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}