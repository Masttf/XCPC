#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<' ';
	// 	for(int j=18;j>=0;j--){
	// 		int d=a[i]>>j&1;
	// 		cout<<d;
	// 	}
	// 	cout<<endl;
	// }
	vector tr(2,vector<int>(20*n));
	vector<int> cnt(20*n);
	int tot=1;
	auto add = [&](int x,int val)->void{
		int p=1;
		for(int i=18;i>=0;i--){
			int d=x>>i&1;
			if(!tr[d][p])tr[d][p]=++tot;
			p=tr[d][p];
			cnt[p]+=val;
		}
	};
	auto dfs = [&](auto self,int x,int p,int i)->pair<int,int>{
		if(i==-1)return {0,0};
		int d=x>>i&1;
		pair<int,int>mx={Max,Max};
		if(cnt[tr[d][p]]){
			mx=self(self,x,tr[d][p],i-1);
			mx.second+=d<<i;
		}
		d^=1;
		if(cnt[tr[d][p]]){
			pair<int,int>temp=self(self,x,tr[d][p],i-1);
			temp.second+=d<<i;
			temp.first++;
			mx=min(mx,temp);
		}
		return mx;
	};
	auto ask = [&](int x)->pair<int,int>{
		int p=1;
		int res=0;
		int num=0;
		for(int i=18;i>=0;i--){
			int d=x>>i&1;
			if(!cnt[tr[d][p]]){
				d^=1;
				num++;
			}
			res+=d<<i;
			p=tr[d][p];
		}
		return {res,num};
	};
	for(int i=1;i<=n;i++)add(a[i],1);
	int res=0;
	int num=n;
	vector<int>ct(1<<18);
	for(int i=1;i<=n;i++)ct[a[i]]++;
	vector<vector<pair<int,int>>>val(20);

	auto updata = [&](int x)->void{
		if(num==0)return ;
		auto [d,p]=dfs(dfs,x,1,18);
		//dbg(x,p,d);
		val[d].push_back({x,p});
		res|=(1<<d);
	};
	num--;
	ct[a[1]]--;
	add(a[1],-1);
	updata(a[1]);
	//dbg("yes");
	int ans=0;
	while(num){
		int t=__lg(lowbit(res));
		if(t==18){
			ans+=num*18;
			break;
		}
		assert(t<=18);
		auto [x,y]=val[t].back();
		//dbg(x,y);
		val[t].pop_back();
		if(val[t].empty())res-=lowbit(res);
		if(ct[y]){
			ct[y]--;
			ans+=t;
			num--;
			add(y,-1);
			
			updata(y);
		}
		updata(x);
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