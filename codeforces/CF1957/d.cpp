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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector pre(35,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			pre[j][i]=pre[j][i-1];
			if(a[i]>>j&1)pre[j][i]++;
		}
	}
	vector cnt1(35,vector<int>(n+1));
	vector cnt2(35,vector<int>(n+1));
	for(int j=0;j<=30;j++)cnt2[j][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			cnt1[j][i]=cnt1[j][i-1];
			cnt2[j][i]=cnt2[j][i-1];
			if(pre[j][i]%2==1)cnt1[j][i]++;
			else cnt2[j][i]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if(a[i]>>j&1){
				//dbg(i,j);
				//dbg(cnt2[j][n],cnt2[j][i-1],cnt1[j][n],cnt1[j][i-1]);
				ans+=(cnt2[j][n]-cnt2[j][i-1])*cnt2[j][i-1]+(cnt1[j][n]-cnt1[j][i-1])*cnt1[j][i-1];
				//dbg(i,j,ans);
				break;
			}
		}
	}
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