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
	map<pair<int,int>,int>m;
	auto dfs = [&](auto self,int l,int r)->void{
		//dbg(l,r);
		if(r-l==1){
			m[{l,r}]++;
			return ;
		}
		for(int i=l;i<=r;i++){
			for(int j=i+1;j<=r;j++){
				if(i==l&&j==r)continue;
				self(self,i,j);
			}
		}
	};
	dfs(dfs,1,n);
	for(auto [x,cnt]:m){
		auto [l,r]=x;
		int tot=0;
		int temp=cnt;
		while(temp&&temp%2==0){
			tot++;
			temp/=2;
		}
		dbg(l,r,cnt,tot);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}