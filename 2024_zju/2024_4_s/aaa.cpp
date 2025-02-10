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
	vector val(n+1,vector<int>(m+1));
	for(int i=1;i<=n*m;i++){
		int x,y;cin>>x>>y;
		val[x][y]=i;
	}
	vector vis(n+1,vector<int>(m+1));
	vis[x1][y1]=1;
	int tx=x1,ty=y1;
	
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