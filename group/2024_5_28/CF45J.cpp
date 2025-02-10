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
void solve(){
	int n,m;cin>>n>>m;
	if(n*m==1){
		cout<<1<<'\n';
		return ;
	}
	if(n*m<=3){
		cout<<-1<<'\n';
		return ;
	}
	if(n*m==4){
		if(n==1){
			cout<<2<<' '<<4<<' '<<1<<' '<<3<<'\n';
		}else if(m==1){
			cout<<2<<'\n'<<4<<'\n'<<1<<'\n'<<3<<'\n';
		}else{
			cout<<-1<<'\n';
		}
		return ;
	}
	if(n==2){
		for(int i=2;i<=n*m;i+=2)cout<<i<<' ';
		cout<<'\n';
		for(int i=5;i<=n*m;i+=2)cout<<i<<' ';
		cout<<1<<' '<<3<<'\n';
		return ;
	}
	vector<int>res(1);
	for(int i=2;i<=n*m;i+=2)res.push_back(i);
	for(int i=1;i<=n*m;i+=2)res.push_back(i);
	int tx=n,ty=m;
	vector<vector<int>>ans(n+1,vector<int>(m+1));
	int now=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=res[now];
			now++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<ans[i][j]<<' ';
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