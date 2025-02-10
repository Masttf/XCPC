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
	int n;cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return ;
	}
	if(n==2){
		cout<<-1<<'\n';
		return ;
	}
	vector ans(n,vector<int>(n));
	if(n%2==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans[i][j]=(i+j)%n;
			}
		}
	}else{
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1;j++){
				ans[i][j]=(i+j)%(n-1);
			}
		}
		ans[n-1][n-1]=n-1;
		for(int i=1,j=0;j<n-1;j++,i++){
			ans[n-1][j]=ans[i%(n-1)][j];
			ans[i%(n-1)][n-1]=ans[i%(n-1)][j];
			ans[i%(n-1)][j]=n-1;
			//dbg(i,j);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]+1<<' ';
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