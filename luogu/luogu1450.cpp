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
constexpr int maxn=1e5+5;
void solve(){
	vector<int>val(5);
	vector<int>cnt(5);
	for(int i=1;i<=4;i++)cin>>val[i];
	vector<int> dp(maxn);
	dp[0]=1;
	for(int i=1;i<=4;i++){
		for(int j=val[i];j<maxn;j++){
			dp[j]+=dp[j-val[i]];
		}
	}
	auto get = [&](int s)->void{
		int ans=0;
		for(int i=0;i<16;i++){
			int tot=s;
			int coef=1;
			for(int j=0;j<4;j++){
				if(i>>j&1){
					coef*=-1;
					tot-=(cnt[j+1]+1)*val[j+1];
				}
			}
			if(tot>=0)ans+=coef*dp[tot];
		}
		cout<<ans<<'\n';
	};
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=4;j++)cin>>cnt[j];
		int s;cin>>s;
		get(s);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}