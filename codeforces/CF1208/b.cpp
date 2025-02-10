#include<bits/stdc++.h>
#define int int long long
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
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	vector<vector<int>>pre(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
			if(a[i][j]=='A')pre[i][j]++;
		}
	}
	if(pre[n][m]==n*m){
		cout<<0<<'\n';
		return ;
	}else if(pre[n][m]==0){
		cout<<"MORTAL\n";
		return ;
	}else{
		int ok1=1,ok2=1;
		for(int i=1;i<=m;i++){
			if(a[1][i]=='P')ok1=0;
			if(a[n][i]=='P')ok2=0;
		}
		if(ok1||ok2){
			cout<<1<<'\n';
			return ;
		}
		ok1=1,ok2=1;
		for(int i=1;i<=n;i++){
			if(a[i][1]=='P')ok1=0;
			if(a[i][m]=='P')ok2=0;
		}
		if(ok1||ok2){
			cout<<1<<'\n';
			return ;
		}
		if(a[1][1]=='A'||a[1][m]=='A'||a[n][1]=='A'||a[n][m]=='A'){
			cout<<2<<'\n';
			return ;
		}
		for(int i=1;i<=n;i++){
			int d=pre[i][m]-pre[i-1][m];
			if(d==m){
				cout<<2<<'\n';
				return ;
			}
		}
		for(int i=1;i<=m;i++){
			int d=pre[n][i]-pre[n][i-1];
			if(d==n){
				cout<<2<<'\n';
				return ;
			}
		}
		ok1=0;
		for(int i=1;i<=m;i++){
			if(a[1][i]=='A')ok1=1;
			if(a[n][i]=='A')ok1=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]=='A')ok1=1;
			if(a[i][m]=='A')ok1=1;
		}
		if(ok1){
			cout<<3<<'\n';
			return ;
		}
		cout<<4<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}