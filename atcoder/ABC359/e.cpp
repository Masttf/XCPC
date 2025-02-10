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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>stk;
	stk.push_back(0);
	a[0]=Max;
	vector<int>val(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&a[stk.back()]<a[i]){
			sum-=val[stk.back()];
			stk.pop_back();
		}
		sum+=a[i]*(i-stk.back());
		val[i]=a[i]*(i-stk.back());
		stk.push_back(i);
		cout<<sum+1<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}