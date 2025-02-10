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
const int Max=1e18;
int dx[]={-1,1,0,0};//U D R L
int dy[]={0,0,1,-1};
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector val(4,vector(n+1,vector<int>(m+1)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			cin>>val[2][i][j];
			val[3][i][j+1]=val[2][i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>val[1][i][j];
			val[0][i+1][j]=val[1][i][j];
		}
	}
	if(k%2==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<-1<<' ';
			}
			cout<<'\n';
		}
		return ;
	}
	k/=2;
	vector dp(k+1,vector(n+1,vector<int>(m+1,Max)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)dp[0][i][j]=0;
	}
	for(int s=1;s<=k;s++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int _=0;_<4;_++){
					int tx=i+dx[_];
					int ty=j+dy[_];
					if(tx<=0||ty<=0||tx>n||ty>m)continue;
					dp[s][i][j]=min(dp[s][i][j],dp[s-1][tx][ty]+val[_][i][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<2*dp[k][i][j]<<' ';
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