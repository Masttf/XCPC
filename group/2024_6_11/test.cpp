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
	int n,m;cin>>n>>m;
	vector<int>a(n);
	
	auto dfs = [&](auto self,int x)->void{
		if(x==n){
			int ok=0;
			for(int i=0;i<n;i++){
				for(int j=i;j<n;j++){
					int sum=0;
					for(int k=i;k<=j;k++){
						sum+=a[k];
					}
					if(sum%m==0)ok=1;
				}
			}
			if(!ok){
				for(auto x:a)cout<<x<<' ';
				cout<<endl;
			}
			return ;
		}
		for(int i=0;i<m;i++){
			a[x]=i;
			self(self,x+1);
		}
	};
	dfs(dfs,0);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}