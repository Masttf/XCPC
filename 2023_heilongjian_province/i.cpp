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
struct node{
	int cnt0,cnt1,tag,l,r;
};
void solve(){
	int n,m;cin>>n>>m;
	vector dp(m+5,vector<double>(m+5));
	int cnta=n%m;
	int cntb=m-cnta;
	int d=n/m;
	//dbg(cnta,cntb,d);
	for(int i=cnta;i>=0;i--){
		for(int j=cntb;j>=0;j--){
			//dbg(i,j);
			if(i==cnta&&j==cntb)continue;
			if(i==0&&j==0){
				dp[i][j]=cnta*(d+1)*1.0/n*dp[i+1][j]+cntb*d*1.0/n*dp[i][j+1]+1;
			}else dp[i][j]=(cnta-i)*(d+1)*1.0/(n-(i+j)*d-i)*dp[i+1][j]+(cntb-j)*d*1.0/(n-(i+j)*d-i)*dp[i][j+1]+n*1.0/(n-(i+j)*d-i);
		}
	}
	//dbg(dp[0][0]);
	cout<<fixed<<setprecision(10)<<dp[0][0]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//
	while(t--)solve();
	return 0;
}