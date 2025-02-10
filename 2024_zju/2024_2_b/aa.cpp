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
	int num1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='X')num1++;
		}
	}
	auto check = [&](int x,int y,int lx,int ly)->bool{
		//dbg(x,y,lx,ly);
		int cnt=0;
		vector vis(n+5,vector<int>(m+5));
		auto bfs = [&]()->void{
			queue<pair<int,int>>q;
			//q.push({x,y});
			vis[x][y]=1;
			cnt++;
			for(int k=0;k<4;k++){
				int tx=x+dx[k];
				int ty=y+dy[k];
				if(a[tx][ty]!='X'&&(tx!=lx||ty!=ly)){
					vis[tx][ty]=1;
					q.push({tx,ty});
					//dbg(tx,ty);
				}
			}
			while(!q.empty()){
				auto [xx,yy]=q.front();
				cnt++;
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
		bfs();
		//dbg(cnt);
		return cnt==num1;
	};
	{
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
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='X')continue;
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
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X')continue;
			//dbg(i,j);
			int num=0;
			for(int k=0;k<4;k++){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if(a[tx][ty]=='0')num++;
			}
			if(a[i][j]=='1'){	
				if(num%2==1){
					if(check(i,j,0,0)){
						cout<<"Yes\n";
						return ;
					}
				}else if(num>0){
					for(int k=0;k<4;k++){
						int tx=i+dx[k];
						int ty=j+dy[k];
						if(a[tx][ty]=='0'){
							if(check(i,j,tx,ty)){
								cout<<"Yes\n";
								return ;
							}
						}
					}
				}
			}else{
				if(num>0&&num%2==0){
					if(check(i,j,0,0)){
						cout<<"Yes\n";
						return ;
					}
				}else if(num>1){
					for(int k=0;k<4;k++){
						int tx=i+dx[k];
						int ty=j+dy[k];
						if(a[tx][ty]=='0'){	
							if(check(i,j,tx,ty)){
								cout<<"Yes\n";
								return ;
							}
						}
					}
				}
				
			}
		}
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}