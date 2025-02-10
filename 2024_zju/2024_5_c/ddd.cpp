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
		//dbg("yes");
	int s=1;
	while(s<=n&&a[s]==0)s++;
	//dbg(s);
	if(s>=n){
		cout<<0<<'\n';
		return ;
	}
	//dbg(s);
	//dbg(s,a[s]);
	vector<int>res;
	if(a[s]<0){
		
		for(int i=1;i<=n+1;i++){
			res.push_back(s);
		}
		for(int i=s+1;i<=n;i++)a[i]+=n*a[s];
		for(int i=n-1;i>=s-1;i--){
			if(a[i+1]>a[i]){
				res.push_back(i);
			}
		}
	}else{
		//vector<int>res;
		for(int i=1;i<=n+1;i++){
			res.push_back(s);
		}
		//dbg(res.size());
		for(int i=s+1;i<=n;i++)a[i]+=n*a[s];
		for(int i=n-1;i>=s-1;i--){
			if(a[i+1]<a[i]){
				res.push_back(i);
			}
		}
	}
	cout<<res.size()<<'\n';
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}