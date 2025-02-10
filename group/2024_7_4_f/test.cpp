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
	// if(n==1000000000ll){
	// 	cout<<934<<'\n';
	// 	return ;
	// }
	int flag=1;
	int now=1;
	for(int i=1;i<=n;i++){
		//cout<<i<<' '<<now<<'\n';
		//dbg(i,now);
		if(i==n){
			cout<<now<<'\n';
		}
		int ok=0;
		if(i%7==0||ok)flag=-flag;
		now+=flag;
		if(now==0)now=1337;
		if(now>1337)now=1;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}