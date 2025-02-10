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
	int m;cin>>m;
	vector<int>cnt(35);
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		if(t==1){
			int x;cin>>x;
			cnt[x]++;
		}else{
			int x;cin>>x;
			int ok=1;
			for(int j=29;j>=0;j--){
				int d=min(x/(1<<j),cnt[j]);
				x-=d*(1<<j);
			}
			if(!x)cout<<"Yes\n"; 
			else cout<<"No\n";
		}
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