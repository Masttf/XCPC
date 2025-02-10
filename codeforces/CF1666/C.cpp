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
	vector<pair<int,int>>a(5);
	vector<int>px;
	vector<int>py;
	for(int i=1;i<=3;i++){
		cin>>a[i].first>>a[i].second;
		px.push_back(a[i].first);
		py.push_back(a[i].second);
	}
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	vector<array<int,4>>res;
	res.push_back({px[0],py[1],px[2],py[1]});
	for(int i=1;i<=3;i++){
		if(a[i].second==py[1])continue;

		res.push_back({a[i].first,a[i].second,a[i].first,py[1]});
	}
	cout<<res.size()<<'\n';
	for(auto [l,r,p,q]:res)cout<<l<<' '<<r<<' '<<p<<' '<<q<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}