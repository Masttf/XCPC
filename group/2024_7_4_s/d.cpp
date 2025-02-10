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
	string s;cin>>s;
	int t1=0;
	int t2=0;
	int flag=0;
	for(auto x:s){
		if(x==':'){
			flag=1;
		}else{
			if(!flag)t1=t1*10+x-'0';
			else t2=t2*10+x-'0';
		}
	}
	int T1=t1*60+t2;
	cin>>s;
	t1=0;
	t2=0;
	flag=0;
	for(auto x:s){
		if(x==':'){
			flag=1;
		}else{
			if(!flag)t1=t1*10+x-'0';
			else t2=t2*10+x-'0';
		}
	}
	int T2=t1*60+t2;
	int tot=T2-T1;
	int n;cin>>n;
	vector<int>t(n+1),c(n+1),p(n+1);
	for(int i=1;i<=n;i++)cin>>t[i]>>c[i]>>p[i];
	vector<int> dp(tot+1);
	for(int i=1;i<=n;i++){
		if(!p[i]){
			for(int j=t[i];j<=tot;j++){
				dp[j]=max(dp[j],dp[j-t[i]]+c[i]);
			}
		}else{
			for(int k=0;(1<<k)<=p[i];k++){
				int num=(1<<k);
				p[i]-=num;
				for(int j=tot;j>=num*t[i];j--){
					dp[j]=max(dp[j],dp[j-num*t[i]]+num*c[i]);
				}
			}
			for(int j=tot;j>=p[i]*t[i];j--){
				dp[j]=max(dp[j],dp[j-p[i]*t[i]]+p[i]*c[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=tot;i++)ans=max(ans,dp[i]);
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