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
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
void solve(){
	int n,m,a,b,c;cin>>n>>m>>a>>b>>c;
	int d=a+b+c;
	vector<array<int,4>>ans;
	map<pair<int,int>,int>vis;
	map<array<int,4>,int>edge;
	int nx=1,ny=1;
	while(c&&ny+2000<=2000*m+1){
		vis[{nx,ny}]=1;
		vis[{nx,ny+2000}]=1;
		edge[{nx,ny,nx,ny+2000}]=1;
		ans.push_back({nx-1,ny-1,nx+1,ny+2001});
		c--;
		nx+=2000;
		if(nx>2000*n+1){
			nx=1;
			ny+=2000;
		}
	}
	while(c){
		assert(ny==m*2000+1);
		vis[{nx,ny}]=1;
		vis[{nx+2000,ny}]=1;
		edge[{nx,ny,nx+2000,ny}]=1;
		ans.push_back({nx-1,ny-1,nx+2001,ny+1});
		c--;
		nx+=2000;
	}
	// for(int i=1;i<=n*2000+1;i+=2000){
	// 	if(!b)break;
	// 	for(int j=1;j<=m*2000+1;j+=2000){
	// 		if(!b)break;
	// 		if(vis.count({i,j}))continue;
	// 		for(int k=0;k<4;k++){
	// 			int tx=i+dx[k]*2000;
	// 			int ty=j+dx[k]*2000;
	// 			if(tx<1||tx>n*2000+1||ty<1||ty>m*2000+1||vis.count({tx,ty}))continue;
	// 			vis[{tx,ty}]=1;
	// 			vis[{i,j}]=1;
	// 			if(k<=1)edge[{tx,ty,i,j}]=1;
	// 			else edge[{i,j,tx,ty}]=1;

	// 		}
	// 	}
	// }
	if(!vis.count({1,1})){
		vis[{1,1}]=1;
		edge[{1,1,1,2001}]=1;
		ans.push_back({0,0,2,2000});
		vis[{1,2001}]=1;
		edge[{1,2001,2001,2001}]=1;
		ans.push_back({0,2000,2000,2002});
	}
	for(int i=2001;i<=n*2000+1;i+=2000){
		if(!vis.count({i,1})){
			vis[{i,1}]=1;
			edge[{i-2000,1,i,1}]=1;
			ans.push_back({i-2000+1,0,i+1,2});
		}
	}
	for(int i=1;i<=n*2000+1;i+=2000){
		for(int j=2001;j<=m*2000+1;j+=2000){
			if(!vis.count({i,j})){
				vis[{i,j}]=1;
				edge[{i,j-2000,i,j}]=1;
				ans.push_back({i-1,j-2000+1,i+1,j+1});
			}
		}
	}
	for(int i=1;i<=n*2000+1;i+=2000){
		for(int j=1;j<m*2000+1;j+=2000){
			if(!edge.count({i,j,i,j+2000})){
				ans.push_back({i-1,j+1,i+1,j+2000-1});
			}
		}
	}
	for(int i=1;i<=m*2000+1;i+=2000){
		for(int j=1;j<n*2000+1;j+=2000){
			if(!edge.count({j,i,j+2000,i})){
				ans.push_back({j+1,i-1,j+2000-1,i+1});
			}
		}
	}
	//cout<<ans.size()<<'\n';
	//assert(d==ans.size());

	for(auto [x,y,p,q]:ans){
		cout<<x/2<<' '<<y/2<<' '<<p/2<<' '<<q/2<<'\n';
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