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
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
void solve(){
	int n,k;cin>>k>>n;
	int ans=0;
	for(int i=0;i<=30;i++){
		if(n>>i&1){
			ans+=qmi(k,i);
		}
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