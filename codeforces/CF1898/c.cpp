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
	int n,m,k;cin>>n>>m>>k;
	int d=n-1+m-1;
	if(k<d||(k-d)%2!=0){
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
	vector res1(n+1,vector<int>(m));
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			res1[i][j]=1;
		}
	}
	if((n-1)%2==0){
		for(int j=1;j<m;j++){
			res1[n][j]=j%2;
		}
	}else{
		for(int j=1;j<m;j++){
			res1[n][j]=1-j%2;
		}
	}
	res1[n-1][m-1]=res1[n][m-1];
	vector res2(m+1,vector<int>(n));
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			res2[i][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		res2[1][i]=i%2;
	}
	res2[m][n-1]=1-res1[n][m-1];
	res2[m-1][n-1]=res2[m][n-1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(res1[i][j])cout<<"R ";
			else cout<<"B ";
		}
		cout<<'\n';
	}
	for(int j=1;j<n;j++){
		for(int i=1;i<=m;i++){
			if(res2[i][j])cout<<"R ";
			else cout<<"B ";
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