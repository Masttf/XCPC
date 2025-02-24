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
	int n, w;
	cin >> n >> w;
	vector<int>cnt(15);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
	}
	vector<int>vis(15);
	int sz=0;
	auto get = [&]()->void{
		vector dp(15,vector (2,vector<int>(w+1)));
		vector pre(15,vector (2,vector<int>(w+1)));
		dp[0][0][0]=1;
		for(int i=1;i<=13;i++){
			if(vis[i]){
				for(int j=0;j<=w;j++){
					if(dp[i-1][0][j]){
						dp[i][0][j]=1;
						pre[i][0][j]=pre[i-1][0][j];
					}else if(dp[i-1][1][j]){
						dp[i][0][j]=1;
						pre[i][0][j]=i-1;
					}
				}
			}else{
				for(int j=0;j<=w;j++){
					if(dp[i-1][0][j]){
						dp[i][0][j]=1;
						pre[i][0][j]=pre[i-1][0][j];
					}else if(dp[i-1][1][j]){
						dp[i][0][j]=1;
						pre[i][0][j]=i-1;
					}
					if(j>=cnt[i]){
						if(dp[i-1][1][j-cnt[i]]){
							dp[i][1][j]=1;
							pre[i][1][j]=i-1;
						}else if(dp[i-1][0][j-cnt[i]]){
							dp[i][1][j]=1;
							pre[i][1][j]=pre[i-1][0][j-cnt[i]];
						}
					}
				}

			} 
		}
		for(int i=w;i>=0;i--){
			//dbg(sz,i);
			if(dp[13][1][i]){
				int now=13;
				int ww=i;
				int last=0;
				while(now){
					//dbg(1,now);
					vis[now]=1;
					sz++;
					last=now;
					now=pre[now][1][ww];
					ww-=cnt[last];
				}
				break;
			}else if(dp[13][0][i]){
				int now=pre[13][0][i];
				int ww=i;
				int last=0;
				while(now){
					vis[now]=1;
					
					sz++;
					last=now;
					now=pre[now][1][ww];
					ww-=cnt[last];
				}
				break;
			}
		}
		return ;
	};
	int ans=0;
	// for(int i=1;i<=13;i++){
	// 	if(sz==13)break;
	// 	get();
	// 	ans++;
	// }
	while(sz<13){
		get();
		ans++;
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}