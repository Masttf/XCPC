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
	vector<array<int,3>>a(n+1);
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x>>y>>z;
		a[i]={x,y,z};
	}
	int ans=0;
	vector<int>val(5);
	auto dfs = [&](auto self,int k)->void{
		if(k==4){
			int ok=1;
			for(int i=1;i<=n;i++){
				auto [x,y,z]=a[i];
				if(z==1){
					if(val[x]>=val[y])ok=0;
				}else{
					if(val[x]<val[y])ok=0;
				}
			}
			ans|=ok;
			return ;
		}
		for(int i=1;i<=3;i++){
			val[k]=i;
			self(self,k+1);
		}
	};
	dfs(dfs,1);
	if(ans)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}