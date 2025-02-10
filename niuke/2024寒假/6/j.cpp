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
	string s;cin>>s;
	s=' '+s;
	vector g(n+1,vector<int>());
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		g[x].push_back(i);
	}
	vector<int>ans(n+1);
	vector<int>sz(n+1);
	vector<int>stk;
	int ok=1;
	auto dfs = [&](auto self,int now,int father)->void{
		stk.push_back(now);
		sz[now]=1;
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			if(s[v]!='R')sz[now]+=sz[v];
		}
		if(s[now]=='R'){
			if(sz[now]==1)ok=0;
			int target;
			if(sz[now]%3==0)target=sz[now];
			else if(sz[now]%3==1)target=2;
			else if(sz[now]%3==2)target=1;
			int y;
			int cnt=0;
			int k=1;
			do{
				y=stk.back();
				stk.pop_back();
				ans[y]=k;
				cnt++;
				if(cnt==target)k=2;
			}while(y!=now);
		}
	};
	dfs(dfs,1,0);
	
	if(!ok)cout<<-1<<'\n';
	else{
		while(!stk.empty()){
			ans[stk.back()]=1;
			stk.pop_back();
		}
		for(int i=1;i<=n;i++)cout<<ans[i];
		cout<<'\n';
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