#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
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
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	int n,m,d;cin>>n>>m>>d;
	vector<string>s(n+1);
	vector<string>b(n+1);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=' '+b[i];
	}
	int mx=n*m*2+1;
	vector<node>e;
	vector g(n*m*3,vector<int>());
	auto add = [&](int u,int v,int w)->void{
		g[u].push_back(e.size());
		e.push_back({v,w});
		g[v].push_back(e.size());
		e.push_back({u,0});
	};
	auto get = [&](int i,int j)->int{
		if(i<=0||i>n||j<=0||j>m)return 2*n*m+1;
		else return (i-1)*m+j;
	};

	auto bfs2 = [&](int x,int y,int v)->void{
		vector vis(n+5,vector<int>(m+5));
		vis[x][y]=1;
		queue<pair<int,int>>q;
		q.push({x,y});
		while(!q.empty()){
			int sz=q.size();
			for(int j=1;j<=sz;j++){
				auto [xx,yy]=q.front();
				q.pop();
				for(int i=0;i<4;i++){
					int tx=xx+dx[i];
					int ty=yy+dy[i];
					if((tx-x)*(tx-x)+(ty-y)*(ty-y)>d*d||vis[tx][ty])continue;
					vis[tx][ty]=1;
					int tar=get(tx,ty);
					add(v,tar,INT_MAX);
					if(tar!=2*n*m+1)q.push({tx,ty});
				}
			}
		}
	};
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u=get(i,j);
			int v=u+n*m;
			if(b[i][j]=='L'){
				add(0,u,1);
				cnt++;
			}
			int w=s[i][j]-'0';
			add(u,v,w);
			bfs2(i,j,v);
		}
	}
	//dbg("yes");
	vector<int>h(mx+1);
	vector<int>cur(mx+1);
	int ss=0,t=mx;
	auto bfs = [&]()->bool{
		h.assign(mx+1,-1);
		h[ss]=0;
		queue<int>q;
		q.push(ss);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto j:g[u]){
				auto [v,w]=e[j];
				if(h[v]==-1&&w){
					h[v]=h[u]+1;
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	};

	auto dfs = [&](auto self,int now,int f)->int{
		if(now==t)return f;
		int res=f;
		for(int &i=cur[now];i<(int)g[now].size();i++){
			int j=g[now][i];
			auto [v,w]=e[j];
			if(h[v]==h[now]+1&&w){
				int dd=self(self,v,min(w,res));
				e[j].w-=dd;
				e[j^1].w+=dd;
				res-=dd;
				if(res==0)return f;
			}
		}
		return f-res;
	};
	int ans=0;
	while(bfs()){
		cur.assign(mx+1,0);
		ans+=dfs(dfs,ss,INT_MAX);
		//dbg(ans);
	}
	cout<<cnt-ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}