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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector l(n+1,vector<array<int,3>>());
	for(int i=1;i<=n;i++){
		int now=a[i];
		int last=i;
		for(auto [x,ll,rr]:l[i-1]){
			int temp=now;
			now=__gcd(now,x);
			if(now!=temp){
				l[i].push_back({temp,rr+1,last});
				last=rr;
			}
		}
		l[i].push_back({now,1,last});
	}
	vector r(n+5,vector<array<int,3>>());
	int mx=0;
	for(int i=n;i>=1;i--){
		int now=a[i];
		int last=i;
		for(auto [x,ll,rr]:r[i+1]){
			int temp=now;
			now=__gcd(now,x);
			if(now!=temp){
				r[i].push_back({temp,last,ll-1});
				last=ll;
			}
		}
		r[i].push_back({now,last,n});
		mx=max(mx,r[i][0][2]-l[i][0][1]);
	}
	set<int>s;
	for(int i=1;i<=n;i++){
		if(r[i][0][2]-l[i][0][1]==mx){
			s.insert(l[i][0][1]);
		}
	}
	cout<<s.size()<<' '<<mx<<'\n';
	for(auto it:s)cout<<it<<' ';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}