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
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans=0;
	for(int i=1;i<=n;i++)ans+=abs(a[i]-b[i]);
	int q1=-LONG_LONG_MAX;
	int q2=-LONG_LONG_MAX;
	int q3=-LONG_LONG_MAX;
	int q4=-LONG_LONG_MAX;
	int sum=ans;
	for(int i=1;i<=n;i++){
		int d=abs(a[i]-b[i]);
		if(i!=1){
			
			ans=max(ans,sum-d+a[i]-b[i]+q1);
			//dbg(i,1,ans);
			ans=max(ans,sum-d-(a[i]+b[i])+q2);
			//dbg(i,2,ans);
			ans=max(ans,sum-d+b[i]-a[i]+q3);
			//dbg(i,3,ans);
			ans=max(ans,sum-d+a[i]+b[i]+q4);
			//dbg(i,4,ans);
		}
		if(a[i]-b[i]-d>q1)q1=a[i]-b[i]-d;
		if(a[i]+b[i]-d>q2)q2=a[i]+b[i]-d;
		if(b[i]-a[i]-d>q3)q3=b[i]-a[i]-d;
		if(-a[i]-b[i]-d>q4)q4=-a[i]-b[i]-d;
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