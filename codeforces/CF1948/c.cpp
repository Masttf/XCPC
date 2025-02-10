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
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void solve(){
	int n;cin>>n;
	vector<string>a(3);
	for(int i=1;i<=2;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	if(n%2==1){
		cout<<"NO\n";
		return ;
	}
	queue<pair<int,int>>q;
	vector vis(3,vector<int>(n+1));
	map<pair<int,int>,int>m;
	vis[1][1]=1;
	q.push({1,1});
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(m[{tx,ty}])continue;
			m[{tx,ty}]=1;
			if(tx==x&&ty==y-1)continue;
			if(tx<1||tx>2||ty<1||ty>n||vis[tx][ty])continue;
			if(a[tx][ty]=='>'){
				if(ty==n)continue;
				q.push({tx,ty+1});
				vis[tx][ty+1]=1;
			}
		}
	}
	if(vis[2][n])cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}