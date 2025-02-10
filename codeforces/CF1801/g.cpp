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
int dx[] ={1,1,0,0,-1,-1};
int dy[]={-1,0,1,-1,0,1};
void solve(){
	int n;cin>>n;
	map<pair<int,int>,int>vis;
	map<int,int>sz;
	map<int,int>f;
	int tot=0;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
		sz[fb]+=sz[fa];
		return ;
	};
	for(int i=1;i<=n;i++){
		int p,x,y;cin>>p>>x>>y;
		if(p==1){
			if(vis.count({x,y}))continue;
			vis[{x,y}]=++tot;
			f[tot]=tot;
			sz[tot]=6;
			int cnt=0;
			for(int j=0;j<6;j++){
				int tx=x+dx[j];
				int ty=y+dy[j];
				if(vis.count({tx,ty})){
					cnt++;
					merge(f[tot],vis[{tx,ty}]);
				}
			}
			int pp=find(find,f[tot]);
			sz[pp]-=2*cnt;
		}else{
			if(!vis.count({x,y}))cout<<0<<'\n';
			else{
				int p=vis[{x,y}];
				p=find(find,p);
				//dbg(i,p);
				cout<<sz[p]<<'\n';
			}
		}
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