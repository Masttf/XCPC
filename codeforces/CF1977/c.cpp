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
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int ok=0;
	for(int i=0;i<n;i++){
		if(a[n-1]%a[i]!=0)ok=1;
	}
	if(ok){
		cout<<n<<'\n';
		return ;
	}
	int ans=0;
	auto check = [&](int x)->void{
		int ok=0;
		for(auto i:a){
			if(i==x)ok=1;
		}
		if(ok)return ;
		int cnt=0;
		int res=1;
		for(auto i:a){
			if(x%i==0){
				cnt++;
				res=lcm(res,i);
			}
		}
		if(res==x)ans=max(ans,cnt);
	};
	for(int i=1;i*i<=a[n-1];i++){
		if(a[n-1]%i==0){
			check(i);
			check(a[n-1]/i);
		}
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