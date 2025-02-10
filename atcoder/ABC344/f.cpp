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
	int n;cin>>n;
	vector p(n+1,vector<int>(n+1));
	vector r(n+1,vector<int>(n+1));
	vector D(n+1,vector<int>(n+1));
	vector<int>pp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			pp.push_back(p[i][j]);
		}
	}
	sort(pp.begin(),pp.end());
	pp.erase(unique(pp.begin(),pp.end()),pp.end());
	auto get = [&](int x)->int{
		return lower_bound(pp.begin(),pp.end(),x)-pp.begin()+1;
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=get(p[i][j]);
			//cout<<p[i][j]<<' ';
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++)cin>>r[i][j];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)cin>>D[i][j];
	}
	vector dp(n+1,vector(n+1,vector<pair<int,int>>(n*n+10,{Max,0})));
	dp[1][1][p[1][1]]={0,0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			// for(int _=1;_<=pp.size();_++){
			// 	dbg(i,j,_,dp[i][j][_].first,dp[i][j][_].second);
			// }
			if(j<n){
				for(int k=1;k<=pp.size();k++){
					if(dp[i][j][k].first==Max)continue;
					//dbg(i,j,k,dp[i][j][k].first);
					auto[d,sum]=dp[i][j][k];
					if(sum>=r[i][j]){
						if(dp[i][j+1][k].first==d+1){
							dp[i][j+1][k].second=max(dp[i][j+1][k].second,sum-r[i][j]);
						}else if(dp[i][j+1][k].first>d+1){
							dp[i][j+1][k]={d+1,sum-r[i][j]};
						}
						if(dp[i][j+1][p[i][j+1]].first==d+1){
							dp[i][j+1][p[i][j+1]].second=max(dp[i][j+1][p[i][j+1]].second,sum-r[i][j]);
						}else if(dp[i][j+1][p[i][j+1]].first>d+1){
							dp[i][j+1][p[i][j+1]]={d+1,sum-r[i][j]};
						}
					}else{
						int dd=((r[i][j]-sum)+pp[k-1]-1)/pp[k-1];
						sum=dd*pp[k-1]+sum-r[i][j];
						//dbg(i,j,k,sum);
						if(dp[i][j+1][k].first==d+dd+1){
							dp[i][j+1][k].second=max(dp[i][j+1][k].second,sum);
						}else if(dp[i][j+1][k].first>d+dd+1){
							dp[i][j+1][k]={dd+d+1,sum};
						}
						if(dp[i][j+1][p[i][j+1]].first==d+dd+1){
							dp[i][j+1][p[i][j+1]].second=max(dp[i][j+1][p[i][j+1]].second,sum);
						}else if(dp[i][j+1][p[i][j+1]].first>d+dd+1){
							dp[i][j+1][p[i][j+1]]={d+dd+1,sum};
						}
					}
				}
			}
			if(i<n){
				for(int k=1;k<=pp.size();k++){
					if(dp[i][j][k].first==Max)continue;
					auto[d,sum]=dp[i][j][k];
					if(sum>=D[i][j]){
						if(dp[i+1][j][k].first==d+1){
							dp[i+1][j][k].second=max(dp[i+1][j][k].second,sum-D[i][j]);
						}else if(dp[i+1][j][k].first>d+1){
							dp[i+1][j][k]={d+1,sum-D[i][j]};
						}
						if(dp[i+1][j][p[i+1][j]].first==d+1){
							dp[i+1][j][p[i+1][j]].second=max(dp[i+1][j][p[i+1][j]].second,sum-D[i][j]);
						}else if(dp[i+1][j][p[i+1][j]].first>d+1){
							dp[i+1][j][p[i+1][j]]={d+1,sum-D[i][j]};
						}
					}else{
						int dd=(D[i][j]-sum+pp[k-1]-1)/pp[k-1];
						sum=dd*pp[k-1]+sum-D[i][j];
						//dbg(i,j,k,sum);
						if(dp[i+1][j][k].first==d+dd+1){
							dp[i+1][j][k].second=max(dp[i+1][j][k].second,sum);
						}else if(dp[i+1][j][k].first>d+dd+1){
							dp[i+1][j][k]={dd+d+1,sum};
						}
						if(dp[i+1][j][p[i+1][j]].first==d+dd+1){
							dp[i+1][j][p[i+1][j]].second=max(dp[i+1][j][p[i+1][j]].second,sum);
						}else if(dp[i+1][j][p[i+1][j]].first>d+dd+1){
							dp[i+1][j][p[i+1][j]]={d+dd+1,sum};
						}
					}
				}
			}
		}
	}
	int ans=Max;
	for(int i=1;i<=n*n;i++){
		ans=min(ans,dp[n][n][i].first);
	}
	if(ans==Max)cout<<-1<<'\n';
	else cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}