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
int dy[]={0,0,1,-1};
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]='X'+a[i]+'X';
	}
	string t="";
	for(int i=0;i<=m+1;i++)t+='X';
	a[0]=t;
	a[n+1]=t;
	// for(int i=0;i<=n+1;i++){
	// 	cout<<a[i]<<'\n';
	// }
	vector<vector<int>>vis(n+5,vector<int>(m+5));
	auto bfs = [&](int x,int y)->void{
		queue<pair<int,int>>q;
		q.push({x,y});
		vis[x][y]=1;
		while(!q.empty()){
			auto [xx,yy]=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int tx=xx+dx[i];
				int ty=yy+dy[i];
				if(a[tx][ty]!='X'&&!vis[tx][ty]){
					vis[tx][ty]=1;
					q.push({tx,ty});
				}
			}
		}
	};
	int cnt=0;
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X')continue;
			num++;
			if(!vis[i][j]){
				cnt++;
				bfs(i,j);
			}
		}
	}
	if(cnt>1||cnt==0){
		cout<<"No\n";
		return ;
	}
	if(num==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='1'){
					cout<<"No\n";
					return ;
				}
				if(a[i][j]=='0'){
					cout<<"Yes\n";
					return ;
				}
			}
		}
	}
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X')continue;
			if(a[i][j]=='1')cnt1++;
			else cnt0++;
		}
	}
	if(cnt0%2==1){
		cout<<"Yes\n";
		return ;
	}else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}