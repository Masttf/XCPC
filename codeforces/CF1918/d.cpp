#include<bits/stdc++.h>
#define int long long
#define Max 1e18
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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=0,r=pre[n];
	int ans=pre[n];
	auto check = [&](int x)->bool{
		vector<int>dp(n+1);
		deque<int>q;
		int l=0;
		int sum=0;
		q.push_back(0);
		for(int i=1;i<=n;i++){
			dp[i]=q.front()+a[i];
			//dbg(x,i,dp[i]);
			sum+=a[i];
			while(!q.empty()&&q.back()>dp[i]){
				q.pop_back();
			}
			q.push_back(dp[i]);
			while(sum-a[l]>x){
				sum-=a[l];
				//dbg(sum,i,a[l],l);
				if(q.front()==dp[l])q.pop_front();
				l++;
			}
			
		}
		int mi=dp[n];
		for(int i=n;i>=0;i--){
			if(pre[n]-pre[i]<=x)mi=min(mi,dp[i]);
		}
		//dbg(x,mi);
		ans=min(ans,max(x,mi));
		return mi<=x;
	};

	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
		}else l=mid+1;
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