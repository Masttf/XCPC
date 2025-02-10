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
	int n,k;cin>>n>>k;
	vector ans(n,vector<int>(k+1));
	int tot=0;
	int l=0;
	for(int i=0;i<n;i++){
		int d=i/k;
		if(d%2==0){
			l=d*k;
			for(int j=1;j<=k;j++)ans[i][j]=++tot;
		}else{
			for(int j=1;j<=k;j++){
				int r=l+j-1;
				if(r>=d*k)r-=k;
				ans[i][j]=ans[r][j];
			}
			l++;
		}
	}
	int Max=5e5;
	//dbg(tot);
	assert(tot<=Max);
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			cout<<ans[i][j]<<' ';
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