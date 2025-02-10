#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		p.push_back(a[i].first);
		p.push_back(a[i].second);
		p.push_back(a[i].first-1);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());

	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	int mx=p.size();
	vector<int>t(mx+1);
	auto updata = [&](int x)->void{
		while(x<=mx){
			t[x]++;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};

	vector q1(mx+1,vector<array<int,3>>());
	vector q2(mx+1,vector<array<int,3>>());
	vector g(mx+1,vector<int>());

	vector<int>ans(n+1);
	for(int i=1;i<=n;i++){
		q1[get(a[i].first-1)].push_back({i,get(a[i].first-1),get(a[i].second)});
		q2[get(a[i].second)].push_back({i,get(a[i].first-1),get(a[i].second)});
		g[get(a[i].first)].push_back(get(a[i].second));
	}
	for(int i=1;i<=mx;i++){
		for(auto x:g[i]){
			updata(x);
		}
		for(auto [id,x,y]:q1[i]){
			ans[id]-=ask(y)-ask(x);
		}
		for(auto [id,x,y]:q2[i]){
			ans[id]+=ask(y)-ask(x);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res+=ans[i]-1;
		//dbg(i,ans[i]);
	}
	cout<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}