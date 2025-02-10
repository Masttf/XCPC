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
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve(){
	int n,m;cin>>n>>m;
	vector ans(n+1,vector<char>(m+1,'#'));
	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	vector<pair<int,int>>a(n*m+1);
	vector<int>f(n*m+1);
	for(int i=1;i<=n*m;i++)f[i]=i;
	auto get = [&](int i,int j)->int{
		return (i-1)*m+j;
	};
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
		return ;
	};
	for(int i=1;i<=n*m;i++){
		int x,y;cin>>x>>y;
		a[i]={x,y};
	}
	for(int i=n*m;i>=1;i--){
		auto [x,y]=a[i];
		ans[x][y]='.';
		for(int k=0;k<4;k++){
			int tx=x+dx[k];
			int ty=y+dy[k];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&ans[tx][ty]=='.'){
				dbg(x,y,tx,ty);
				merge(get(x,y),get(tx,ty));
			}
		}
		dbg(find(find,get(x1,y1)),find(find,get(x2,y2)));
		if(find(find,get(x1,y1))==find(find,get(x2,y2)))break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
		}
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