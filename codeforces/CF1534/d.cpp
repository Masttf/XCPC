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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<vector<int>>g(n+1);
	cout<<"? 1"<<endl;
	vector<int>dep(n+1);
	for(int i=1;i<=n;i++)cin>>dep[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(dep[i]%2==1)cnt++;
	}
	int tg=1;
	if(cnt>=(n+1)/2)tg=0;
	for(int i=1;i<=n;i++){
		if(dep[i]%2==tg){
			vector<int>temp(n+1);
			if(i==1){
				temp=dep;
			}else{
				cout<<"? "<<i<<endl;
				for(int i=1;i<=n;i++)cin>>temp[i];
			}
			for(int j=1;j<=n;j++){
				if(temp[j]==1){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
	}
	cout<<"!"<<endl;
	auto dfs = [&](auto self,int now,int father)->void{
		for(auto v:g[now]){
			if(v==father)continue;
			cout<<now<<' '<<v<<endl;
			self(self,v,now);
		}
	};
	dfs(dfs,1,0);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}