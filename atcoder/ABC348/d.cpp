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
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vector val(n+1,vector<int>(m+1));
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x,y,v;cin>>x>>y>>v;
		val[x][y]=max(v,val[x][y]);
	}
	auto dij= [&](int x,int y)->bool{
		priority_queue<array<int,3>>q;
		vector d(n+1,vector<int>(m+1,-1));
		vector vis(n+1,vector<int>(m+1));
		d[x][y]=val[x][y];
		q.push({d[x][y],x,y});
		while(!q.empty()){
			auto [w,tx,ty]=q.top();
			if(a[tx][ty]=='T')return true;
			q.pop();
			if(w==0)continue;
			for(int j=0;j<4;j++){
				int ux=tx+dx[j];
				int uy=ty+dy[j];
				if(ux>=1&&ux<=n&&uy>=1&&uy<=m&&a[ux][uy]!='#'&&d[ux][uy]<d[tx][ty]-1){
					d[ux][uy]=max(val[ux][uy],d[tx][ty]-1);
					q.push({d[ux][uy],ux,uy});
				}
			}
		}
		return false;
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='S'){
				if(dij(i,j))cout<<"Yes\n";
				else cout<<"No\n";
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}