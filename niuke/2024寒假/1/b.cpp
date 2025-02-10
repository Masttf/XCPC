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
	int n;cin>>n;
	if(n==0){
		cout<<3<<'\n';
		return ;
	}
	vector<pair<int,int>>res(n+1);
	vector<int>p;
	p.push_back(0);
	p.push_back(-1);
	p.push_back(1);
	for(int i=1;i<=n;i++){
		cin>>res[i].first>>res[i].second;
		p.push_back(res[i].second);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	int idx=get(0);
	vector<int>cnt(n+10);
	for(int i=1;i<=n;i++){
		res[i].second=get(res[i].second);
		cnt[res[i].second]++;
	}
	int ans=3;
	int res1=2,res2=2;
	for(int i=1;i<idx;i++){
		res1=min(res1,2-cnt[i]);
	}
	for(int i=idx+1;i<=n+7;i++){
		res2=min(res2,2-cnt[i]);
	}
	ans=min(ans,res1+res2);
	int ct=0;
	for(int i=1;i<=n;i++){
		if(res[i].first==1){
			if(res[i].second==get(-1)||res[i].second==get(1))ct++;
		}else{
			if(res[i].second==idx)ct++;
		}
	}
	ans=min(ans,3-ct);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--){
		solve();
		//dbg(t);
	}
	return 0;
}