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
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	vector<int>tr1(n+1),tr2(n+1);
	auto add = [&](int x,int val)->void{
		while(x<=n){
			tr1[x]+=val;
			tr2[x]++;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->pair<int,int>{
		int res1=0,res2=0;
		while(x){
			res1+=tr1[x];
			res2+=tr2[x];
			x-=lowbit(x);
		}
		return {res1,res2};
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		auto [x,y]=ask(get(a[i])-1);
		//dbg(x,y,get(a[i]));
		ans+=y*a[i]-x;
		add(get(a[i]),a[i]);
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