#include<bits/stdc++.h>
#define int long long
using namespace std;
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
constexpr int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>ps(m+2);
	vector<vector<pair<int,int>>>xx(n+1),yy(n+1);
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		ps[i]={x,y};
	}
	cin>>ps[0].first>>ps[0].second>>ps[m+1].first>>ps[m+1].second;
	for(int i=0;i<=m+1;i++){
		auto [x,y]=ps[i];
		xx[x].push_back({y,i});
		yy[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++){
		sort(xx[i].begin(),xx[i].end());
		sort(yy[i].begin(),yy[i].end());
	}
	vector<vector<int>>g(m+5);
	for(int i=1;i<=n;i++){
		int sz=xx[i].size();
		for(int j=0;j<sz;j++){
			int u=xx[i][j].second;
			int v;
			if(j>=1){
				v=xx[i][j-1].second;
				g[u].push_back(v);
			}
			if(j+1<sz){
				v=xx[i][j+1].second;
				g[u].push_back(v);
			}
		}
		sz=yy[i].size();
		for(int j=0;j<sz;j++){
			int u=yy[i][j].second;
			int v;
			if(j>=1){
				v=yy[i][j-1].second;
				g[u].push_back(v);
			}
			if(j+1<sz){
				v=yy[i][j+1].second;
				g[u].push_back(v);
			}
		}
	}
	auto dij = [&](int s,int t)->void{
		vector d(2,vector<int>(m+5,Max));
		priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
		d[0][s]=0;
		d[1][s]=0;
		q.push({0,0,s});
		q.push({0,1,s});//0 x 1 y
		while(!q.empty()){
			auto [w,f,u]=q.top();
			q.pop();
			if(w>d[f][u])continue;
			//dbg(w,f,ps[u].first,ps[u].second);
			for(auto v:g[u]){
				if(!f){
					if(ps[v].first==ps[u].first){
						if(d[f][v]>d[f][u]+2*abs(ps[u].second-ps[v].second)){
							d[f][v]=d[f][u]+2*abs(ps[u].second-ps[v].second);
							q.push({d[f][v],f,v});
						}
					}else{
						if(d[1-f][v]>d[f][u]+1+2*abs(ps[u].first-ps[v].first)){
							d[1-f][v]=d[f][u]+1+2*abs(ps[u].first-ps[v].first);
							q.push({d[1-f][v],1-f,v});
						}
					}
				}else{
					if(ps[v].second==ps[u].second){
						if(d[f][v]>d[f][u]+2*abs(ps[u].first-ps[v].first)){
							d[f][v]=d[f][u]+2*abs(ps[u].first-ps[v].first);
							q.push({d[f][v],f,v});
						}
					}else{
						if(d[1-f][v]>d[f][u]+1+2*abs(ps[u].second-ps[v].second)){
							d[1-f][v]=d[f][u]+1+2*abs(ps[u].second-ps[v].second);
							q.push({d[1-f][v],1-f,v});
						}
					}
				}
			}
		}
		int mi=min(d[0][t],d[1][t]);
		if(mi==Max){
			cout<<-1<<'\n';
		}else cout<<mi<<'\n';
		return ;
	};
	dij(0,m+1);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}