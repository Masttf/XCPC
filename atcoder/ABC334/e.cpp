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
const int mod=998244353;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vector vis(n+1,vector<int>(m+1));
	int cnt=0;
	auto bfs = [&](int x,int y)->void{
		cnt++;
		queue<pair<int,int>>q;
		q.push({x,y});
		vis[x][y]=cnt;
		while(!q.empty()){
			auto [tx,ty]=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int ttx=tx+dx[i];
				int tty=ty+dy[i];
				if(ttx>=1&&ttx<=n&&tty>=1&&tty<=m&&!vis[ttx][tty]&&a[ttx][tty]=='#'){
					vis[ttx][tty]=cnt;
					q.push({ttx,tty});
				}
			}
		}
	};
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.')tot++;
			else if(!vis[i][j])bfs(i,j);
		}
	}
	//dbg(cnt);
	if(tot==0){
		cout<<cnt<<'\n';
		return ;
	}else{
		int p=qmi(tot,mod-2);
		int ans=0;
		auto get = [&](int x,int y)->int{
			set<int>s;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='#'){
					s.insert(vis[tx][ty]);
				}
			}
			if(s.empty())return cnt+1;
			else return cnt-(s.size()-1);
		};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='.'){
					//dbg(i,j,get(i,j));
					ans+=get(i,j)*p%mod;
					if(ans>=mod)ans-=mod;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}