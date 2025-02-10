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
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++)cin>>a[i][j];
    }
	if(n==1 && m==1){
		cout<<-1<<'\n';
		return ;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			cout<<a[i%n][0]<<'\n';
		}
		return ;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j%m]<<' ';
		}
		cout<<'\n';
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