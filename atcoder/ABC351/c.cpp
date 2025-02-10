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
	vector<int>res;
	for(int i=1;i<=n;i++){
		res.push_back(a[i]);
		while(res.size()>1){
			int sz=res.size();
			if(res[sz-2]!=res[sz-1])break;
			int d=res.back()+1;
			//dbg(i,d,res[sz-1],res[sz-2]);
			res.pop_back();
			res.pop_back();
			res.push_back(d);
		}
	}
	cout<<res.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}