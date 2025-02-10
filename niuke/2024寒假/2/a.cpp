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
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;cin>>a>>b>>c;
		int ans=0;
		if(a==150)ans+=1;
		else if(a==200)ans+=2;
		if(b>=29&&b<=32)ans+=0;
		else if(b==45)ans+=2;
		else ans+=1;
		if(c>=29&&c<=32)ans+=0;
		else if(c==45)ans+=2;
		else ans+=1;
		cout<<ans<<'\n';
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