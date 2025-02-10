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
	string a,b;cin>>a>>b;
	int n=a.size();
	int m=b.size();
	a=' '+a;
	b=' '+b;
	vector dp(n+1,vector<int>(m+1));
	vector pre(n+1,vector<int>(m+1));
	for(int i=0;i<=m;i++)dp[0][i]=i,pre[0][i]=3;
	for(int i=0;i<=n;i++)dp[i][0]=i,pre[i][0]=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1];
				pre[i][j]=1;
			}else{
				dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
				if(dp[i][j]==dp[i-1][j-1]+1)pre[i][j]=4;
				else if(dp[i][j]==dp[i-1][j]+1)pre[i][j]=2;
				else pre[i][j]=3;
			}
		}
	}
	cout<<dp[n][m]<<'\n';
	int nn=n,mm=m;
	while(nn||mm){
		if(pre[nn][mm]==1){
			nn--;
			mm--;
		}else if(pre[nn][mm]==2){
			cout<<"DELETE "<<nn<<'\n';
			nn--;
		}else if(pre[nn][mm]==3){
			cout<<"INSERT "<<nn+1<<' '<<b[mm]<<'\n';
			mm--;
		}else{
			cout<<"REPLACE "<<nn<<' '<<b[mm]<<'\n';
			nn--;
			mm--;
		}
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