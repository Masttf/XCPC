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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>p;
	int mx=1e8;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push_back(a[i]);
		p.push_back(mx-a[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	int m=p.size()+1;
	vector<int>tr(m+1);
	auto add = [&](int x)->void{
		while(x<=m){
			tr[x]++;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	int ans=0;
	vector<int>suf(n+5);
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	for(int i=n;i>=1;i--){
		ans+=suf[i+1]+(n-i)*a[i];
		ans-=mx*((n-i)-ask(get(mx-a[i])-1));
		add(get(a[i]));
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}