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
	vector<string>a(n+1);
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		len+=a[i].size();
	}
	vector tr(26,vector<int>(len+5));
	vector<int>cnt(len+5);
	cnt[1]=1;
	int tot=1;
	auto add = [&](string x)->void{
		int p=1;
		for(auto it:x){
			if(!tr[it-'a'][p])tr[it-'a'][p]=++tot;
			p=tr[it-'a'][p];
		}
		cnt[p]++;
	};
	for(int i=1;i<=n;i++)add(a[i]);

	int ans=len;
	vector<multiset<int>>res(len+5);
	auto mg = [&](int x,int y)->void{
		if(res[x].size()<res[y].size())swap(res[x],res[y]);
		res[x].insert(res[y].begin(),res[y].end());
	};
	vector<int>dep(len+5);
	auto dfs = [&](auto self,int now)->void{
		//dbg(now);
		for(int i=0;i<26;i++){
			if(!tr[i][now])continue;
			dep[tr[i][now]]=dep[now]+1;
			self(self,tr[i][now]);
			mg(now,tr[i][now]);
		}
		if(cnt[now])res[now].insert(dep[now]);
		else{
			auto it =res[now].rbegin();
			ans-=*it-dep[now];
			auto itt=res[now].find(*it);
			res[now].erase(itt);
			res[now].insert(dep[now]);
		}
	};
	dfs(dfs,1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}