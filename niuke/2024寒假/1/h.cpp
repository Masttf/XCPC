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
	int n,m;cin>>n>>m;
	//dbg(n,m);
	vector<int>w(n+1),v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	int ans=0;
	auto check = [&](int x)->void{
		int res=0;
		for(int i=1;i<=n;i++){
			if((w[i]|x)==x){
				res+=v[i];
			}
		}
		ans=max(ans,res);
		//dbg(x,res);
	};
	for(int i=30;i>=0;i--){
		if(m>>i&1){
			check((m^(1<<i))|((1<<i)-1));
		}
	}
	check(m);
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