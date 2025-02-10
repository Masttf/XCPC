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
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	vector dp(m+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=2;i<=m;i++){
		if(a[i]>1&&a[i-1]>1){
			for(int j=1;j+a[i]-1<=n;j++){
				int d1=j-a[i-1]+1;
				int d2=j+a[i]-1;
				if(d1>=1)dp[i][j]|=dp[i-1][d1];
				if(d2<=n)dp[i][j]|=dp[i-1][d2];
			}
		}else if(a[i]==1){
			vector<pair<int,int>>temp;
			for(int j=1;j<=n;j++){
				if(dp[i-1][j]){
					temp.push_back({j,j+a[i-1]-1});
				}
			}
			int ll=1,rr=0;
			for(auto [l,r]:temp){
				if(l<=rr)rr=r;
				else{
					if(ll<=rr){
						for(int j=ll;j<=rr;j++)dp[i][j]=1;
					}
					ll=l,rr=r;
				}
			}
			if(ll<=rr){
				for(int j=ll;j<=rr;j++)dp[i][j]=1;
			}
		}else{
			vector<int>pre(n+1);
			for(int j=1;j<=n;j++)pre[j]=pre[j-1]+dp[i-1][j];
			for(int j=1;j+a[i]-1<=n;j++){
				int d=pre[j+a[i]-1]-pre[j-1];
				if(d)dp[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=dp[m][i];
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}