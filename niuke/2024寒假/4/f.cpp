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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector dpmax(n+1,vector(n+1,vector<int>(10)));
	vector dpmin(n+1,vector(n+1,vector<int>(10)));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=0;k<=6;k++){
				dpmax[i][j][k]=dpmax[i][j-1][k];
				dpmin[i][j][k]=dpmin[i][j-1][k];
			}
			for(int k=1;k<=min(j-i+1,6ll);k++){
				if(k==j-i+1){
					if(k==1){
						dpmax[i][j][k]=dpmin[i][j][k]=a[j];
					}else if(k==2||k==4||k==6){
						dpmax[i][j][k]=dpmin[i][j][k]=dpmax[i][j-1][k-1]-a[j];
					}else{
						dpmax[i][j][k]=dpmin[i][j][k]=dpmax[i][j-1][k-1]*a[j];
					}
				}else{
					if(k==1){
						dpmax[i][j][k]=max(dpmax[i][j][k],a[j]);
						dpmin[i][j][k]=min(dpmin[i][j][k],a[j]);
					}else if(k==2||k==4||k==6){
						dpmax[i][j][k]=max({dpmax[i][j-1][k-1]-a[j],dpmin[i][j-1][k-1]-a[j],dpmax[i][j][k]});
						dpmin[i][j][k]=min({dpmax[i][j-1][k-1]-a[j],dpmin[i][j-1][k-1]-a[j],dpmin[i][j][k]});
					}else{
						dpmax[i][j][k]=max({dpmax[i][j-1][k-1]*a[j],dpmin[i][j-1][k-1]*a[j],dpmax[i][j][k]});
						dpmin[i][j][k]=min({dpmax[i][j-1][k-1]*a[j],dpmin[i][j-1][k-1]*a[j],dpmin[i][j][k]});
					}
				}
			}
		}
	}
	vector<int>dp(n+1);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],dp[j]+dpmax[j+1][i][6]);
		}
	}
	//dbg(dpmax[1][6][6]);
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
