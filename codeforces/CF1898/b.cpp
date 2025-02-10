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
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]){
			if(a[i]%a[i+1]==0){
				ans+=a[i]/a[i+1]-1;
				a[i]=a[i+1];
			}else{
				int k=(a[i]+a[i+1]-1)/a[i+1];
				ans+=k-1;
				a[i]=a[i]/k;
				//dbg(res);
			}
			
		}
		//dbg(i,a[i]);
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