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
constexpr int M=1e5+5;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	int ok=0;
	for(int i=1;i<=n;i++){
		auto dfs = [&](auto self,int now,int sum)->void{
			//dbg(now,sum);
			if(now==n+1){
				//dbg(a[i],sum);
				if(sum==a[i]||sum==-a[i])ok=1;
				return ;
			}
			self(self,now+1,sum);
			if(now!=i){
				self(self,now+1,sum+a[now]);
				self(self,now+1,sum-a[now]);
			}
		};
		dfs(dfs,1,0);
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}