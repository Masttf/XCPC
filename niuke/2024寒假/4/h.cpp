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
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	// for(int i=40;i<=45;i++){
	// 	for(int j=121;j<=127;j++){
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<'\n';
	// }
	vector f(n+5,vector<bitset<3005>>(m+5));
	vector f2(n+5,vector<bitset<3005>>(m+5));
	vector f3(n+5,vector<bitset<3005>>(m+5));
	vector f4(n+5,vector<bitset<3005>>(m+5));
	vector f5(n+5,vector<bitset<3005>>(m+5));
	int ans=0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			f4[i][j]=f4[i+1][j+1]<<1;
			f5[i][j]=f5[i+1][j-1]<<1;
			if(a[i][j]=='*'){
				f2[i][j]=f2[i+1][j+1]<<1;
				f3[i][j]=f3[i+1][j-1]<<1;
				int l=j-1;
				int r=j+1;
				f2[i][j][0]=1;
				f3[i][j][0]=1;
				f4[i][j][0]=1;
				f5[i][j][0]=1;
				if(i<n&&l>=1&&r<=m&&a[i+1][l]=='*'&&a[i+1][r]=='*'){
					f[i][j]=((f[i+1][l]&f2[i+1][r]&f4[i+1][j])<<1)|((f3[i+1][l]&f[i+1][r]&f5[i+1][j])<<1);
					if(a[i+1][j]=='*')f[i][j][1]=1;
				}
				//int d=f[i][j].count();
				//dbg(i,j,d);
				ans+=f[i][j].count();
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		dbg(i,j,f[i][j]);
	// 		dbg(i,j,f2[i][j]);
	// 		dbg(i,j,f3[i][j]);
	// 	}
	// }
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
